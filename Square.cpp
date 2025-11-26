#include "Square.h"
#include <cmath>

int Square::x() const {
  return std::abs(data[0].x() - data[2].x());
}
int Square::y() const {
  return std::abs(data[0].y() - data[2].y());
}
int Square::abs_sqr() const {
  return x()*x() + y()*y();
}

frame_t Square::frame() const {
  return frame_t(data[0].x(), data[0].y(), data[2].x(), data[2].y());
}
double Square::getArea() const {
  return std::abs(x()*y());
}

Square::Square(Point lb, Point ur) {
  data[0] = lb;
  data[1] = Point(lb.x(), ur.y());
  data[2] = ur;
  data[3] = Point(ur.x(), lb.y());
}