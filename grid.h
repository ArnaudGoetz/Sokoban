#ifndef GRID_HEADER
#define GRID_HEADER

enum CaseType{
	WALL = '#',
	BOX = '$',
	PLAYER = '@',
	GOAL = '.',
	NONE = ' ', 
	PLAYER_GOAL = 'P',
	BOX_GOAL = 'B'
};
/**
 * @struct Grid grid.h
 * @brief Cette structure contient les informations 
 * concernant la grille du jeu et son contenu
 */
struct Grid{
	enum CaseType** game_grid; ///< Tableau contenant les entités présents dans le jeu
	int column_number; ///< Nombre de colonne de game_grid
	int row_number; ///< Nombre de ligne de game_grid
	struct Player *player; ///< Structure représentant le joueur
	int goal_number; ///< Nombre de but total
	int goals_covered; ///< Nombre de but recouverts
};
struct Grid* init_level(const char* file_path);
int check_finish(struct Grid* niveau);
void display(struct Grid* niveau);

#include "player.h"

#endif
