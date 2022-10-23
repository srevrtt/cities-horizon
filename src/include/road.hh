#pragma once

#include <map>
#include "image.hh"
#include "window.hh"

enum RoadType
{
  SIMPLE_PAVED,
  SIMPLE_GRAVEL
};

class Road
{
private:
  std::map<int, Image *> roads;
  Window *window;
  int currentIdx;
public:
  Road(Window *window);

  void addRoad(RoadType type);
  void render();
};
