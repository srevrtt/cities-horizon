#include <iostream>
#include <string>

#include "include/window.hh"

#include <SDL.h>
#include <SDL_image.h>

bool windowCreated = false;

// Creates a cross platform window
Window::Window(unsigned int width, unsigned int height, std::string title)
{
  // Only create a window once
  if (!windowCreated)
  {
    windowCreated = true;
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
      title.c_str(),
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      width,
      height,
      SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if (!window)
    {
      std::cout << "Error: Failed to create a Window.\n";
      exit(1);
    }

    SDL_SetWindowMinimumSize(window, 320, 180);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
      std::cout << "Error: Failed to create a renderer.\n";
      exit(1);
    }
  }
}

// Clears the window's renderer
void Window::clear()
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
}

// Renders everything from the window's renderer to the screen
void Window::display()
{
  SDL_RenderPresent(renderer);
}

// Closes the window
void Window::close()
{
  if (window && renderer)
  {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    delete this;
  }
}
