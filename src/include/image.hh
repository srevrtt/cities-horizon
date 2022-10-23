#pragma once

#include <SDL.h>
#include "window.hh"

class Image
{
private:
  SDL_Rect dst;
  SDL_Texture *texture;
  Window *window;
public:
  Image(Window *window, int x, int y, unsigned int width, unsigned int height, const char *filepath);
  void render();
};
