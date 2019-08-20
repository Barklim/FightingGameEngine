#include "graphics/GameTexture.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

GameTexture::GameTexture(){ }
GameTexture::~GameTexture(){ }

bool GameTexture::loadTexture(const char* path){
  SDL_Surface* img = IMG_Load(path);
  if(img == NULL){
    printf("Error loading image with path %s, error: %s", path, IMG_GetError());
    return false;
  }

  SDL_FreeSurface(img);

  return true;
}

void GameTexture::render() {
}

void GameTexture::incTransperancy(){
  alpha++;
  setTransperancy(alpha);
}

void GameTexture::decTransperancy(){
  alpha++;
  setTransperancy(alpha);

}

void GameTexture::setTransperancy(uint8_t tran){
  alpha = tran;
  SDL_SetTextureAlphaMod(texture, alpha);
}

uint8_t GameTexture::getTransperancy(){
  return alpha;
}

void GameTexture::setBlendMode(SDL_BlendMode mode){
  SDL_SetTextureBlendMode(texture, mode);
}


void GameTexture::setCords(int xCord, int yCord) { 
  textRect.x = xCord;
  textRect.y = yCord;
}

void GameTexture::setDimensions(int xCord, int yCord, int width, int height) { 
  textRect.x = xCord;
  textRect.y = yCord;
  textRect.w = width;
  textRect.h = height;
}

std::pair<int, int> GameTexture::getDimensions() { 
  return std::make_pair(textRect.w, textRect.h);
}

std::pair<int, int> GameTexture::getCords() { 
  return std::make_pair(textRect.x, textRect.y);
}
