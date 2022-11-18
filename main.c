/** \file main.c
	* \author TEISSANDIER
	* \author GOETZ
	*/

#include <stdio.h>
#include "grid.h"
#include "player.h"
#include <stdbool.h>
#include "sdl2.h"

/**
 * @brief Fonction input
 * 
 * @return char 
 */
char input() {
	char result = 0;
	while (result != 'e' && result != 'z' && result != 'q' && result != 's' && result != 'd')
		result = fgetc(stdin);
	return result;
}

void display_sdl2(struct Grid* niveau) {
	SDL_SetRenderDrawColor(context.renderer, 0, 0, 0, 255); // couleur noire
	SDL_RenderClear(context.renderer); // On dessine toute la fenêtre en noir
	for (int i = 0; i < niveau->row_number; i++) {
		for (int j = 0; j < niveau->column_number; j++) {
			SDL_Rect rect = {    .x = j*(context.width/niveau->column_number),
												.y = i*(context.height/niveau->row_number),
												.w = (context.width/niveau->column_number),
												.h = (context.height/niveau->row_number)
										};
			if (niveau->game_grid[i][j] == WALL) 
				SDL_SetRenderDrawColor(context.renderer, 255, 255, 255, 255); // on choisit la couleur blanche
			if (niveau->game_grid[i][j] == BOX || niveau->game_grid[i][j] == BOX_GOAL) 
				SDL_SetRenderDrawColor(context.renderer, 138, 64, 0, 255); // on choisit la couleur brune
			if (niveau->game_grid[i][j] == PLAYER || niveau->game_grid[i][j] == PLAYER_GOAL) 
				SDL_SetRenderDrawColor(context.renderer, 255, 255, 0, 255); // on choisit la couleur jaune
			if (niveau->game_grid[i][j] == GOAL) 
				SDL_SetRenderDrawColor(context.renderer, 0, 255, 0, 255); // on choisit la couleur verte
			if (niveau->game_grid[i][j] == NONE) 
				SDL_SetRenderDrawColor(context.renderer, 0, 0, 0, 255); // on choisit la couleur noire
			
			SDL_RenderFillRect(context.renderer, &rect); // On dessine le rectangle
		}
	}
	
	SDL_RenderPresent(context.renderer); // On affiche tout
}

/**
 * \brief Fonction main
 * \return 0 ! (normalement)
 */
int main(void){
	char* chemin = "level1.txt";
	struct Grid *niveau = init_level(chemin);
	printf("Nombre de ligne \t: %d\n", niveau->row_number);
	printf("Nombre de colonnes \t: %d\n", niveau->column_number);

	sdl_init();
	
	bool run = true;
	char entry;
	while(run){
		display_sdl2(niveau);
		if (check_finish(niveau)) entry = 'e';
		else entry = input();
		switch(entry){
			case 'e' :{
				run = false;
				sdl_quit();
				break;
			}
			default: move_player(niveau, ((enum Direction) entry)); break;
		}
	}
}

