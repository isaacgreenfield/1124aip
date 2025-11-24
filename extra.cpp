#include "Point.h"
#include "extra.h"
#include "Vector.h"
#include <stdexcept>
#include <iostream>
#include <cstddef>

Planar * make(size_t id) {
  Point * r = nullptr;
  switch (id) {
    case(0):
      r = new Point(0, 0);
    case(1):
      r = new Vector();
    default:
      throw std::logic_error("bad id");
  }
  return r;
}

void free_planars(Planar ** pls, size_t k) {
  for (size_t i = 0; i < k; ++i) {
    delete pls[i];
  }
}

void draw(Planar *pl) {
  std::cout << pl->x() << " " << pl->y() << "\n";
}

Planar *most_left(Planar **pls, size_t k) {
  return nullptr;
}