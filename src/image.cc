#include <iostream>
#include <string>

#include "include/image.hh"
#include "include/window.hh"

#include <SDL.h>
#include <SDL_image.h>

// Creates a new image with the specified size, position, and file path
Image::Image(Window *window, int x, int y, unsigned int width, unsigned int height, const char *filepath)
{
  this->dst = { x, y, (int)width, (int)height };
  
  SDL_Surface *sur = IMG_Load(filepath);
  texture = SDL_CreateTextureFromSurface(window->getRenderer(), sur);

  SDL_FreeSurface(sur);
  this->window = window;
}

// Draws the image onto the screen
void Image::render()
{
  SDL_RenderCopy(window->getRenderer(), texture, nullptr, &dst);
}
