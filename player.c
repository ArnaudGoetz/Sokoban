/**
 * @file player.c
 * 
 */

#include "player.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Fonction testant et effectuant si possible le déplacement de la boîte située à la position (x,y) dans le niveau dans la direction dir
 * 
 * @param niveau 
 * @param x 
 * @param y 
 * @param dir 
 * @return int un booléen indiquant si le déplacement a été effectué
 */
int move_box(struct Grid* niveau, int x, int y, enum Direction dir) {
  int move_x = dir == TOP ? -1 : (dir == BOTTOM ? 1 : 0);
  int move_y = dir == LEFT ? -1 : (dir == RIGHT ? 1 : 0);
  // printf("Dans move_box : \nnouv_x = %d\nnouv_y = %d\n", x+move_x, y+move_y);
  if ((niveau->game_grid[x+move_x][y+move_y] != WALL) && (niveau->game_grid[x+move_x][y+move_y] != BOX)){
    if (niveau->game_grid[x][y] == BOX_GOAL) {
      niveau->goals_covered--;
      niveau->game_grid[x][y] = GOAL;
    }
    if (niveau->game_grid[x+move_x][y+move_y] == GOAL) {
      niveau->game_grid[x+move_x][y+move_y] = BOX_GOAL;
      niveau->goals_covered++;
    }
    else {
      niveau->game_grid[x+move_x][y+move_y] = BOX;
      // printf("J'ai déplacé la box ! Il y a maintenant : %c\n", (char)niveau->game_grid[x+move_x][y+move_y] );

    }
    return 1;
  }
  return 0;
}

/**
 * @brief Fonction effectuant le déplacement du joueur, s'il est possible dans la direction dir
 * 
 * @param niveau 
 * @param dir 
 */
void move_player(struct Grid* niveau, enum Direction dir) {
  int move_x = dir == TOP ? -1 : (dir == BOTTOM ? 1 : 0);
  int move_y = dir == LEFT ? -1 : (dir == RIGHT ? 1 : 0);
  // printf("Dans move_player : \nnouv_x = %d\nnouv_y = %d\n", niveau->player->x+move_x, niveau->player->y+move_y);
  if (niveau->game_grid[niveau->player->x+move_x][niveau->player->y+move_y] != WALL) {
    
    if (niveau->game_grid[niveau->player->x+move_x][niveau->player->y+move_y] == BOX || niveau->game_grid[niveau->player->x+move_x][niveau->player->y+move_y] == BOX_GOAL) 
      { if (!move_box(niveau, niveau->player->x+move_x, niveau->player->y+move_y, dir)) return; }
    
    if (niveau->game_grid[niveau->player->x+move_x][niveau->player->y+move_y] == GOAL) niveau->game_grid[niveau->player->x+move_x][niveau->player->y+move_y] = PLAYER_GOAL;
    else niveau->game_grid[niveau->player->x+move_x][niveau->player->y+move_y] = PLAYER;
    
    if (niveau->game_grid[niveau->player->x][niveau->player->y] == PLAYER_GOAL) niveau->game_grid[niveau->player->x][niveau->player->y] = GOAL;
    else niveau->game_grid[niveau->player->x][niveau->player->y] = NONE;

    niveau->player->x += +move_x;
    niveau->player->y += +move_y;
  }
}