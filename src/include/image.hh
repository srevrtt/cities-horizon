#pragma once

#include <SDL.h>
#include "window.hh"

class Image
{
private:
  SDL_Rect dst;
  SDL_Rect src;
  SDL_Texture *texture;
  Window *window;
public:
  Image(Window *window, int x, int y, int srcX, int srcY, int srcWidth, int srcHeight, unsigned int width, unsigned int height, const char *filepath);
  void render();
};
