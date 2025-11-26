#ifndef VECTOR_H
#define VECTOR_H
#include "Planar.h"
#include "Point.h"

struct Vector: Planar {

  int NAME = 2;

  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;

  virtual double getArea() const;
  virtual frame_t frame() const;

  Vector(Point p1, Point p2);
  virtual ~Vector() = default;

private:
  Point start;
  Point end;
};
#endif
