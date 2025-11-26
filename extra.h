#ifndef EXTRA_H
#define EXTRA_H
#include <iosfwd>
#include "Planar.h"

Planar * make(std::istream& is);
Planar * make(size_t id);
void draw(Planar ** pl);
void free_planars(Planar ** pls, size_t k);
Planar ** most_left(Planar ** pls, size_t k);
#endif
