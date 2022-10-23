#include <iostream>
#include <string>
#include <map>

#include <SDL.h>

#include "include/road.hh"
#include "include/image.hh"

Road::Road(Window *window)
{
  this->window = window;
  currentIdx = 1;
}

void Road::addRoad(RoadType type)
{
  int srcX = 0;
  int srcY = 0;
  
  if (type == RoadType::SIMPLE_GRAVEL)
  {
    srcX = 22;
  }

  Image *img = new Image(window, currentIdx * 99, 200, srcX, srcY, 22, 11, 99, 50, "../res/gfx/roads.png");
  currentIdx++;

  roads.insert({
    currentIdx,
    img
  });
}

void Road::render()
{
  for (auto &road : roads)
  {
    // std::cout << "e";
    road.second->render();
  }

  // std::cout << " ";
}
