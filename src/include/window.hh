#pragma once

#include <SDL.h>
#include <string>

class Window
{
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
public:
  Window(unsigned int width, unsigned int height, std::string title);
  
  void clear();
  void display();
  void close();

  SDL_Renderer *getRenderer();
};
