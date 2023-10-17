#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "pong.h"

class UI {
  Field field;
  sf::RenderWindow& window;
  double scale;

 public:
  UI(sf::RenderWindow&, Field f);
  void run();

 private:
  void process_keypress(sf::Event keypress);
  void redraw();
};

#endif  // #ifndef UI_H
