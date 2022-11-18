#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "grid.h"

enum Direction {
  TOP = 'z',
  BOTTOM = 's',
  LEFT = 'q',
  RIGHT = 'd'
};

/**
 * @struct Player player.h
 * @brief Cette structure contient la position en x et en y actuelle du joueur
 * 
 */
struct Player {
  int x; ///< Position en x du joueur
  int y; ///< Position en y du joueur
};

int move_box(struct Grid* niveau, int x, int y, enum Direction dir);
void move_player(struct Grid* niveau, enum Direction dir);

#endif