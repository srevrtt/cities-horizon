#pragma once

#include <string>
#include <vector>

#include "window.hh"
#include "image.hh"

class Text
{
private:
  int x, y;
  std::vector<Image*> chars;
  Window *window;
public:
  Text(int x, int y, std::string text, Window *window);
  void render();
};
