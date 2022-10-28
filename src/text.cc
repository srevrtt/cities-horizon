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
      std::cout << (int)chr << '\n';

      img = new Image(window, newX, y, (chr - 48) * 6, 0, 6, 7, 42, 49, "../res/gfx/font.png");
      newX += 48;
    }

    // TODO: exceptions for letters M, O, Q, and W

    if (islower(chr))
    {
      img = new Image(window, newX, y, (chr - 97) * 6, 14, 6, 8, 42, 49, "../res/gfx/font.png");
      newX += 97;
    }

    if (isupper(chr))
    {
      img = new Image(window, newX, y, (chr - 65) * 6, 7, 6, 8, 42, 49, "../res/gfx/font.png");

      if (chr == 'I')
      {
        newX += 12;
      }
      else if (chr == 'F')
      {
        newX += 36;
      }
      else
      {
        newX += 42;
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
