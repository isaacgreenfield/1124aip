
#ifndef SQUARE_H
#define SQUARE_H
#include "Planar.h"
#include "Point.h"

struct Square:Planar {

  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;

  virtual double getArea() const;
  virtual frame_t frame() const;

  Square(Point lb, Point ur);

private:
  Point data[4] = {};
};

#endif
