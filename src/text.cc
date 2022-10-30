#include <iostream>
#include <string>

#include "include/text.hh"
#include "include/image.hh"

// Creates a road of text
Text::Text(int x, int y, std::string text, Window *window)
{
  int newX = x;

  for (auto &chr : text)
  {
    Image *img;

    if (isdigit(chr))
    {
      img = new Image(window, newX, y, (chr - 48) * 6, 0, 6, 7, 42, 49, "../res/gfx/font.png");
      newX += 48;
    }

    if (islower(chr))
    {
      img = new Image(window, newX, y, (chr - 97) * 6, 14, 6, 8, 42, 49, "../res/gfx/font.png");
      newX += 97;
    }

    if (isupper(chr))
    {
      img = new Image(window, newX, y, (chr - 65) * 11, 9, 11, 8, 55, 49, "../res/gfx/font.png");

      if (chr == 'I')
      {
        newX += 20;
      }
      else if (chr == 'W')
      {
        newX += 45;
      }
      else
      {
        newX += 40;
      }
    }

    chars.push_back(img);
  }
}

// Renders that text
void Text::render()
{
  for (auto &chr : chars)
  {
    chr->render();
  }
}
