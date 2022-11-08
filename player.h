#ifndef PLAYER_HEADER
#define PLAYER_HEADER

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

#endif