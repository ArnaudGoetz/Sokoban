/**
	* \file grid.c
	*/

#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * \brief Fonction init_level
 * \param file_path Chemin du fichier à charger
 * \return Rien !
 */

struct Grid* init_level(const char* file_path){
	struct Grid *niveau = malloc(sizeof (struct Grid));
	niveau->game_grid = malloc(100 * sizeof (enum CaseType*));
	for (int i = 0; i<100; i++) {
		niveau->game_grid[i] = malloc(100 * sizeof (enum CaseType));
	}
	
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
	int current_row = 0;
	int current_column = 0;
	int current_goal = 0;
	// On lit le fichier ligne par ligne jusqu'à la fin du fichier
	while(fgets(line, 100, file) != NULL){
		char* buffer = line;
		current_column = 0;
		while(*buffer && *buffer != '\n'){
			// printf("%c ", line[current_column]);
			niveau->game_grid[current_row][current_column] = (enum CaseType)line[current_column];
			current_column += 1;
			buffer += 1;
		}		
		// printf("\n");
		current_row += 1;
	}
	niveau->column_number = current_column;
	niveau->row_number = current_row;
	// fermeture du fichier
	fclose(file);
	return niveau;
}

void display(struct Grid* niveau) {
	for (int i = 0; i < niveau->row_number; i++) {
		for (int j = 0; j < niveau->column_number; j++) {
			printf("%c", (char)niveau->game_grid[i][j]);
		}
		printf("\n");
	}
}
