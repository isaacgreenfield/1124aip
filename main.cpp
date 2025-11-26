#include <iostream>
#include "Planar.h"
#include "extra.h"

int main() {
  size_t s = 0;
  size_t c = 20;
  Planar ** pls = new Planar*[c];

  while (std::cin) {
    Planar * pl = nullptr;
    try {
      pl = make(std::cin);
      if (s == c) {
        Planar ** epls = new Planar*[2*c];
        for (size_t i = 0; i <s; ++i) {
          epls[i] = pls[i];
        }
        delete[] pls;
        pls = epls;
        c *= 2;
      }
      pls[s++] = pl;
    } catch (...) {
      delete[] pl;
      free_planars(pls, s);
      return 2;
    }
  }
  if (!std::cin.eof()) {
    free_planars(pls, s);
    return 3;
  }

  draw(most_left(pls, s));

  free_planars(pls, s);

  return 0;
}