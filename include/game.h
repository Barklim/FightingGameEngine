#ifndef _game_h
#define _game_h

#include "graphics.h"
#include "inputManager.h"
#include "gameState.h"
#include "observer.h"


class Game : public Observer{
public:
  Game();
  ~Game();
  void init();
  void run();
  bool stillRunning();
  void onNotify(const char* message);

private:
  /* data */
  Graphics coreGraphics;
  InputManager inputManager;
  GameState* currentState;
  bool running;
};
#endif /* ifndef _game_h */
