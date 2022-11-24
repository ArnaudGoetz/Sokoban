/**
 * @file main.h
 * Contient les include du main et l'Enum Event
 */

#include <stdio.h>
#include "grid.h"
#include "player.h"
#include <stdbool.h>
#include "sdl2.h"

/**
 * @brief Enumération Event
 * Les valeurs correspondent aux touches clavier z,q,s,d et e pour quitter
 * 
 */
enum Event {
  Quit = 'e',
  Up = 'z',
  Down = 's',
  Left = 'q',
  Right = 'd'
};