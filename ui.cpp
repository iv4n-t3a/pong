#include "ui.h"

#include <assert.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono;

UI::UI(sf::RenderWindow& w, Field f) : window(w), field(f) {
  sf::Vector2u size = window.getSize();
  scale = std::min(size.x / field.w, size.y / field.h);
  redraw();
}
void UI::run() {
  sf::Event event;

  const int delay = 100000;
  time_point<system_clock> next_update = system_clock::now() + microseconds(delay);
  while (window.isOpen()) {
    redraw();

    if (system_clock::now() > next_update) {
      field.move_ball();
      next_update += microseconds(delay);
    }

    if (field.s != PLAYING)
      std::exit(0);

    if (not window.pollEvent(event))
      continue;

    if (event.type == sf::Event::KeyPressed) {
      process_keypress(event);
    } else if (event.type == sf::Event::Closed) {
      exit(0);
    }
  }
}
void UI::process_keypress(sf::Event keypress) {
  assert(keypress.type == sf::Event::KeyPressed or keypress.type == sf::Event::KeyReleased);
  switch (keypress.key.code) {
    case sf::Keyboard::S:
      field.move_up(PLAYER1);
      break;
    case sf::Keyboard::W:
      field.move_down(PLAYER1);
      break;

    case sf::Keyboard::Down:
      field.move_up(PLAYER2);
      break;
    case sf::Keyboard::Up:
      field.move_down(PLAYER2);
      break;

    default:
      break;
  }
}
void UI::redraw() {
  window.clear(sf::Color::Black);

  sf::RectangleShape ball(sf::Vector2f(scale, scale));
  ball.setPosition(sf::Vector2f(scale * field.b.pos.x, scale * field.b.pos.y));
  window.draw(ball);

  for (Player p : {PLAYER1, PLAYER2}) {
    sf::RectangleShape platform(sf::Vector2f(scale, scale * field.pf[p].len));
    platform.setPosition(sf::Vector2f(scale * field.pf[p].pos.x, scale * field.pf[p].pos.y));
    window.draw(platform);
  }

  window.display();
}
