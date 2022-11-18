#include <stdio.h>
#include "grid.h"
#include "player.h"
#include <stdbool.h>
#include "sdl2.h"

enum Event {
  Quit = 'e',
  Up = 'z',
  Down = 's',
  Left = 'q',
  Right = 'd'
};