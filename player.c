#include "player.h"
#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

void move_player(struct Grid* niveau, enum Direction dir) {
  printf("%d, %d, %c\n", niveau->player->x,niveau->player->y, (char)dir);
  switch(dir){
    case 'z' :{
      if (((char)niveau->game_grid[niveau->player->x-1][niveau->player->y] != '#')
      && ((char)niveau->game_grid[niveau->player->x-1][niveau->player->y] != '$')) {
        niveau->game_grid[niveau->player->x-1][niveau->player->y] = '@';
        niveau->game_grid[niveau->player->x][niveau->player->y] = ' ';
        niveau->player->x--;
      }
      break;
    }
    case 's' :{
      if (((char)niveau->game_grid[niveau->player->x+1][niveau->player->y] != '#')
      && ((char)niveau->game_grid[niveau->player->x+1][niveau->player->y] != '$')) {
        niveau->game_grid[niveau->player->x+1][niveau->player->y] = '@';
        niveau->game_grid[niveau->player->x][niveau->player->y] = ' ';
        niveau->player->x++;
      }
      break;
    }
    case 'q' :{
      if (((char)niveau->game_grid[niveau->player->x][niveau->player->y-1] != '#')
      && ((char)niveau->game_grid[niveau->player->x][niveau->player->y-1] != '$')) {
        niveau->game_grid[niveau->player->x][niveau->player->y-1] = '@';
        niveau->game_grid[niveau->player->x][niveau->player->y] = ' ';
        niveau->player->y--;
      }
      break;
    }
    case 'd' :{
      if (((char)niveau->game_grid[niveau->player->x][niveau->player->y+1] != '#')
      && ((char)niveau->game_grid[niveau->player->x][niveau->player->y+1] != '$')) {
        niveau->game_grid[niveau->player->x][niveau->player->y+1] = '@';
        niveau->game_grid[niveau->player->x][niveau->player->y] = ' ';
        niveau->player->y++;
      }
      break;
    }
  }
}