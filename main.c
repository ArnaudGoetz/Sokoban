/** \file main.c
	* \author TEISSANDIER
	* \author GOETZ
	*/

#include "main.h"
#include <string.h>

/**
 * @brief Fonction input du terminal
 * 
 * @return enum Event 
 */
enum Event event() {
	char result = 0;
	while (result != 'e' && result != 'z' && result != 'q' && result != 's' && result != 'd')
		result = fgetc(stdin);
	return (enum Event) result;
}

/**
 * @brief Fonction d'input de SDL2
 * 
 * @return enum Event 
 */
enum Event event_sdl2() {
	SDL_Event ev;
	while (true) {
		SDL_WaitEvent(&ev);
		switch (ev.type){
			case SDL_QUIT:
					// on a appuyé sur le bouton "quitter" de la fenêtre
					return Quit;
			case SDL_KEYUP:
					// on a relaché une touche du clavier.
					switch (ev.key.keysym.sym) {
						case SDLK_UP:
							return Up;
						case SDLK_DOWN:
							return Down;
						case SDLK_LEFT:
							return Left;
						case SDLK_RIGHT:
							return Right;
						default:
							return Quit;
					};
		}
	}
	
}

/**
 * @brief Fonction d'affichage pour la SDL2
 * 
 * @param niveau Le niveau à afficher
 */
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
 * \return 0 si le programme s'est terminé sans erreurs
 */
int main(int argc, char* argv[]){
	char* chemin = "level1.txt";
	struct Grid *niveau = init_level(chemin);
	printf("Nombre de ligne \t: %d\n", niveau->row_number);
	printf("Nombre de colonnes \t: %d\n", niveau->column_number);
	
	bool run = true;
	char entry;
	void (*handle_display)(struct Grid*) = &display; 
	enum Event (*handle_event)() = &event;

	char* char_sdl = "--sdl2";
	if (argc == 2 && !strcmp(argv[1], char_sdl)) {
		handle_display = &display_sdl2;
		handle_event = &event_sdl2;
		sdl_init();
	}

	while(run){
		(*handle_display)(niveau);
		if (check_finish(niveau)) entry = 'e';
		else entry = (*handle_event)();
		switch(entry){
			case 'e' :{
				run = false;
				sdl_quit();
				break;
			}
			default: move_player(niveau, ((enum Direction) entry)); break;
		}
	}
	return 0;
}

