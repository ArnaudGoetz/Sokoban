/**
 * @file player.h
 */

#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "grid.h"

/**
 * @brief Enum Direction
 * 
 */
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

void move_player(struct Grid* niveau, enum Direction dir);
#endif