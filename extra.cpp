#include "Point.h"
#include "extra.h"
#include "Vector.h"
#include <stdexcept>
#include <iostream>
#include <cstddef>

Planar * make(size_t id) {
  Planar * r = nullptr;
  switch (id) {
    case(0):
      r = new Point(0, 0);
    case(1):
      r = new Vector(Point(0, 0), Point(1, 1));
    default:
      throw std::logic_error("bad id");
  }
  return r;
}

Planar * make(std::istream& is) {
  int data[4] = {};
  char cmd[2] = {};
  is >> cmd[0] >> cmd[1];
  if (cmd[0] == 'P' && cmd[1] == 'T') {
    if (is >> data[0] >> data[1]) {
      return new Point(data[0], data[1]);
    }
  } else if (cmd[0] == 'V' && cmd[1] == 'T') {
    if (is >> data[0] >> data[1] >> data[2] >> data[3]) {
      return new Vector(Point(data[0], data[1]), Point(data[2], data[3]));
    }
  }
  throw std::logic_error("bad cmd");
}

void free_planars(Planar ** pls, size_t k) {
  for (size_t i = 0; i < k; ++i) {
    delete pls[i];
  }
  delete[] pls;
}

void draw(Planar **pl) {
  std::cout << (*pl)->x() << " " << (*pl)->y() << "\n";
}

Planar ** most_left(Planar **pls, size_t k) {
  if (!k) {
    return pls;
  }
  Planar ** res = pls;
  while (--k) {
    int next_x = (*(++pls))->x();
    int curr_x = (*res)->x();
    if (next_x < curr_x) {
      res = pls;
    }
  }
  return res;
}