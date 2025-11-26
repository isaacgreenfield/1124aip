
#include "Vector.h"
#include <cmath>

Vector::Vector(Point p1, Point p2):
Planar(), start(Point(p1.x(), p1.y())), end(Point(p2.x(), p2.y())){}

int Vector::x() const {
  return end.x() - start.x();
}
int Vector::y() const {
  return end.y() - start.y();
}

int Vector::abs_sqr() const {
  return x()*x() + y()*y();
}

double Vector::getArea() const {
  frame_t tmp = frame();
  return std::abs((tmp.x2 - tmp.x1)*(tmp.y2 - tmp.y1));
}
frame_t Vector::frame() const {
  return frame_t(end.x(), end.y(), start.x(), start.y());
}
