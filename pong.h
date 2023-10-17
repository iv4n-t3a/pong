#ifndef PONG
#define PONG

#include <assert.h>

#include <array>
#include <iostream>

struct Vector {
  int x, y;
};
typedef Vector Dot;

inline Vector operator*(Vector const& a, double k) {
  return {k * a.x, k * a.y};
}
inline void operator+=(Vector& a, Vector const& b) {
  a = {a.x + b.x, a.y + b.y};
}

struct Ball {
  Dot pos = {40, 20};
  Vector dir = {1, 1};
  double speed = 1;
};
struct Platform {
  Dot pos;
  int len = 8;
};

enum Player {
  PLAYER1,
  PLAYER2
};
enum State {
  PLAYING,
  PLAYER1_WIN,
  PLAYER2_WIN
};

struct Field {
  int w = 80, h = 40;
  std::array<Platform, 2> pf;
  Ball b;
  State s = PLAYING;

  Field() {
    pf[0].pos = {2, 15};
    pf[1].pos = {78, 15};
  }
  void move_down(Player);
  void move_up(Player);
  void move_ball();
};
inline void Field::move_down(Player p) {
  pf[p].pos.y = std::max(0, pf[p].pos.y - 2);
}
inline void Field::move_up(Player p) {
  pf[p].pos.y = std::min(h - pf[p].len, pf[p].pos.y + 2);
}
inline void Field::move_ball() {
  assert(s == PLAYING);

  b.pos += b.dir * b.speed;

  for (Player p : {PLAYER1, PLAYER2})
    if (b.pos.x == pf[p].pos.x) {
      if (b.pos.y > pf[p].pos.y + pf[p].len or b.pos.y < pf[p].pos.y)
        s = PLAYER1_WIN;
      else
        b.dir = {-b.dir.x, b.dir.y};
    }

  if (b.pos.y >= h or b.pos.y < 0)
    b.dir = {b.dir.x, -b.dir.y};
}

#endif  // #ifndef PONG
