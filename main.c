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

