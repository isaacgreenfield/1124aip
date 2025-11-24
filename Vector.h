#ifndef VECTOR_H
#define VECTOR_H
#include "Planar.h"
#include "Point.h"

struct Vector: Planar {

  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;

  Vector(Point p1, Point p2);
  virtual ~Point() = default;

private:
  Point start;
  Point end;
};
#endif
