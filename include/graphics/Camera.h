#ifndef _Camera_h
#define _Camera_h

#include "Graphics.h"

class Camera {
public:
  Camera();
  ~Camera();

  void update(int p1Xpos, int p2Xpos);
  void render();
  void moveCamera();
  SDL_Rect cameraRect;

  int lowerBound;
  int upperBound;
private:
  Graphics* graphics = Graphics::getInstance();
};

#endif /* _Camera_h */
