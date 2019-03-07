#ifndef _MenuState_h
#define _MenuState_h

#include "states/GameState.h"
#include "StateManager.h"

class MenuState : public GameState{
public:
  MenuState();
  ~MenuState();

  void enter();
  void exit();

  void handleInput(StateManager* sm, VirtualController* vc);
  void update();
  void draw(SDL_Renderer* renderer);

private:
  enum menu { VERSUS, CONFIG };
  int menuCounter = 0;
};
#endif
