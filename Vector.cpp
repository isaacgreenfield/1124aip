
#include "Vector.h"

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
