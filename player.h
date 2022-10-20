#ifndef PLAYER_HEADER
#define PLAYER_HEADER

enum Direction {
  Top = 'z',
  Bottom = 's',
  Left = 'q',
  Right = 'd'
};

struct Player {
  int x;
  int y;
};

#endif