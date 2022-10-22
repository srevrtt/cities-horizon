#include <iostream>
#include <string>

#include <SDL.h>

int main(int argc, char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO);
  std::cout << "Hello world!\n";

  return 0;
}
