/** \file main.c
	* \author TEISSANDIER
	* \author GOETZ
	*/

#include <stdio.h>
#include "grid.h"
#include <stdbool.h>

/**
 * @brief Fonction d'input
 * 
 * @return char 
 */
char input() {
	char result = 0;
	while (result != 'e' && result != 'z' && result != 'q' && result != 's' && result != 'd')
		result = fgetc(stdin);
	return result;
}


/**
 * \brief La fonction main, initialise le jeu, lit et traite les input du joueur
 * \return 0
 */

int main(void){
	char* chemin = "level1.txt";
	struct Grid *niveau = init_level(chemin);
	printf("Nombre de ligne \t: %d\n", niveau->row_number);
	printf("Nombre de colonnes \t: %d\n", niveau->column_number);
	// display(niveau);
	
	bool run = true;
	char entry;
	while(run){
		display(niveau);
		if (check_finish(niveau)) entry = 'e';
		else entry = input();
		switch(entry){
			case 'e' :{
				run = false;
				break;
			}
			default: move_player(niveau, ((enum Direction) entry)); break;
		}
	}
}

