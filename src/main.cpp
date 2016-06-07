#include "../include/Game.hpp"

int
main ()
{
  Game game (1000, 1000);

  game.menu ();
  game.start ();

  return 0;

}
