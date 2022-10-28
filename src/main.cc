#include <iostream>
#include <string>

#include <SDL.h>

#include "include/window.hh"
#include "include/image.hh"
#include "include/road.hh"
#include "include/text.hh"

// FPS limiting variables
double frameStart, frameTime;
const double frameDelay = 1000 / 60;

SDL_Event event;

int main(int argc, char *argv[])
{
  Window *window = new Window(1280, 720, "Cities Horizon");
  Road *road = new Road(window);
  Text *testText = new Text(10, 10, "QWERTYUIOPASDFGHJKLZXBNM", window);

  bool running = true;
  while (running)
  {
    frameStart = SDL_GetTicks();

    // Event handling
    if (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_F2:
          road->addRoad(RoadType::SIMPLE_PAVED);
          break;
        case SDLK_F1:
          road->addRoad(RoadType::SIMPLE_GRAVEL);
          break;
        }
        break;
      }
    }

    // Rendering
    window->clear();

    road->render();
    testText->render();

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
