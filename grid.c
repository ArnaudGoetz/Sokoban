/**
	* \file grid.c
	*/

#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * \brief Fonction init_level
 * \param file_path Chemin du fichier à charger
 * \return struct Grid* Le niveau chargé
 */
struct Grid* init_level(const char* file_path){
	// ouverture du fichier en mode lecture
	FILE* file = fopen(file_path, "r");
	if(!file){
		fprintf(stderr, "Error %s not found", file_path);
		exit(-1);
	}
	char line[100] = {0};
	int number_column = 0; // nombre de colonne
	int number_row = 0; // nombre de ligne
	int number_goals = 0;
	// on lit la première ligne du fichier
	fgets(line, 100, file);
	sscanf(line, "%d %d %d", &number_column, &number_row, &number_goals);

	struct Grid *niveau = ((struct Grid*)malloc(sizeof (struct Grid)));
	niveau->game_grid = (enum CaseType**)malloc(number_row * sizeof (enum CaseType*));
	for (int i = 0; i<number_row; i++) {
		niveau->game_grid[i] = (enum CaseType*)malloc(number_column * sizeof (enum CaseType));
	}
	niveau->player = (struct Player*)malloc(sizeof (struct Player));

	int current_row = 0;
	int current_column = 0;
	// On lit le fichier ligne par ligne jusqu'à la fin du fichier
	while(fgets(line, 100, file) != NULL){
		char* buffer = line;
		current_column = 0;
		while(*buffer && *buffer != '\n'){
			// printf("%c ", line[current_column]);
			if ((enum CaseType)line[current_column] == '@') {
				niveau->player->x = current_row;
				niveau->player->y = current_column;
			}
			niveau->game_grid[current_row][current_column] = (enum CaseType)line[current_column];
			current_column += 1;
			buffer += 1;
		}		
		// printf("\n");
		current_row += 1;
	}
	niveau->column_number = number_column;
	niveau->row_number = number_row;
	niveau->goal_number = number_goals;
	niveau->goals_covered = 0;
	// fermeture du fichier
	fclose(file);
	return niveau;
}

/**
 * @brief Fonction testant si le niveau est complété
 * 
 * @param niveau 
 * @return int un booleen indiquant si le niveau est complété
 */
int check_finish(struct Grid* niveau) {
	return (niveau->goal_number == niveau->goals_covered);
}

/**
 * @brief Fonction d'affichage du niveau
 * 
 * @param niveau 
 */
void display(struct Grid* niveau) {
	for (int i = 0; i < niveau->row_number; i++) {
		for (int j = 0; j < niveau->column_number; j++) {
			if (niveau->game_grid[i][j] == PLAYER_GOAL) {
				printf("%c", PLAYER);
			}
			else if (niveau->game_grid[i][j] == BOX_GOAL) {
				printf("%c", BOX);
			}
			else {
				printf("%c", (char)niveau->game_grid[i][j]);
			}
		}
		printf("\n");
	}
}

/**
 * @brief Fonction pour free la mémoire allouée
 * 
 * @param niveau 
 */
void free_grid(struct Grid* niveau) {
	free(niveau->player);
	for (int i = 0; i<niveau->row_number; i++) {
		free(niveau->game_grid[i]);
	}
	free(niveau->game_grid);
	free(niveau);
}
