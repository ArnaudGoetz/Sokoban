/** \file main.c
	* \author TEISSANDIER
	* \author GOETZ
	*/

#include <stdio.h>
#include "grid.h"
#include <stdbool.h>

/**
 * \brief The main Function
 * \return 0 !
 */

int main(void){
	char* chemin = "level1.txt";
	struct Grid *niveau = init_level(chemin);
	printf("Nombre de ligne \t: %d\n", niveau->row_number);
	printf("Nombre de colonnes \t: %d\n", niveau->column_number);
	display(niveau);
	
	bool run = true;
	while(run){
		char entry = fgetc(stdin);
		switch(entry){
			case 'q' :{
				run = false;
				break;
			}
		}
	}
}

