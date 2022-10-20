/** \file main.c
	* \author TEISSANDIER
	* \author GOETZ
	*/

#include <stdio.h>
#include "grid.h"
#include <stdbool.h>


char input() {
	char result = 0;
	while (result != 'e' && result != 'z' && result != 'q' && result != 's' && result != 'd')
		result = fgetc(stdin);
	return result;
}


/**
 * \brief The main Function
 * \return 0 !
 */

int main(void){
	char* chemin = "level1.txt";
	struct Grid *niveau = init_level(chemin);
	printf("Nombre de ligne \t: %d\n", niveau->row_number);
	printf("Nombre de colonnes \t: %d\n", niveau->column_number);
	// display(niveau);
	
	bool run = true;
	while(run){
		display(niveau);
		char entry = input();
		switch(entry){
			case 'e' :{
				run = false;
				break;
			}
			default: move_player(niveau, ((enum Direction) entry)); break;
		}
	}
}

