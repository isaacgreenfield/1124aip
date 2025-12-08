#ifndef PLANAR_H
#define PLANAR_H
#include <algorithm>
struct Planar {

  int NAME = 0;

  virtual int x() const = 0;
  virtual int y() const = 0;
  virtual int abs_sqr() const = 0;
  virtual ~Planar() = default;

  virtual double getArea() const;
  virtual frame_t frame() const;
};
struct frame_t {
  int x1, y1;
  int x2, y2;

  frame_t(int xx1, int yy1, int xx2, int yy2);
};

Planar ** max_area(Planar ** pls, size_t k);
Planar *** max_frame_intersects(Planar ** pls, size_t k);
void free_intersection_result(Planar ***result);
#endif
