#include <iostream>
#include <string>

#include <SDL.h>
#include "include/window.hh"

// FPS limiting variables
double frameStart, frameTime;
const double frameDelay = 1000 / 60;

SDL_Event event;

int main(int argc, char *argv[])
{
  Window *window = new Window(1280, 720, "Cities Horizon");

  while (true)
  {
    frameStart = SDL_GetTicks();

    // Event handling
    if (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        break;
      }
    }

    // Rendering
    window->clear();
    window->display();

    // FPS limiting
    frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > frameTime)
    {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  window->close();
  return 0;
}
