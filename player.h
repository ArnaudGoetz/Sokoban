#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "grid.h"

enum Direction {
  TOP = 'z',
  BOTTOM = 's',
  LEFT = 'q',
  RIGHT = 'd'
};

struct Player {
  int x;
  int y;
};

void move_player(struct Grid* niveau, enum Direction dir);
#endif