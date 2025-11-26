#include "Planar.h"

frame_t::frame_t(int xx1, int yy1, int xx2, int yy2): x1(xx1), y1(yy1), x2(xx2), y2(yy2) {}

Planar **max_area(Planar **pls, size_t k) {
  Planar ** curr = &pls[0];
  for (size_t i = 1; i < k; ++i) {
    if (pls[i]->getArea() > (*curr)->getArea()) (*curr) = pls[i];
  }
  return curr;
}

Planar ***max_frame_intersects(Planar **pls, size_t k) {
  double area = -1;
  Planar *** plx = new Planar ** [2];
  for (size_t i = 0; i < k; ++i) {
    for (size_t j = i + 1; j<k; ++j) {
      ...
    }
  }
  return nullptr;
}
