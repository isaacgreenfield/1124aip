
#ifndef POINT_H
#define POINT_H
#include "Planar.h"
struct Point: Planar {

  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;

  Point(int xx, int yy);
  virtual ~Point() = default;

private:
  int data[2];
};
#endif
