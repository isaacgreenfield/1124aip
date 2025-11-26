#ifndef PLANAR_H
#define PLANAR_H
struct Planar {
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
#endif
