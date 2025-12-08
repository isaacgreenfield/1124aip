#include "Planar.h"

frame_t::frame_t(int xx1, int yy1, int xx2, int yy2): x1(xx1), y1(yy1), x2(xx2), y2(yy2) {}

Planar **max_area(Planar **pls, size_t k) {
  Planar ** curr = &pls[0];
  for (size_t i = 1; i < k; ++i) {
    if (pls[i]->getArea() > (*curr)->getArea()) (*curr) = pls[i];
  }
  return curr;
}

Planar ***max_frame_intersects(Planar **pls, size_t k) {
    if (k < 2) {
        return nullptr;
    }

    double max_intersection_area = -1.0;
    size_t max_i = 0, max_j = 0;
    bool found = false;

    for (size_t i = 0; i < k; ++i) {
        for (size_t j = i + 1; j < k; ++j) {
            frame_t frame1 = pls[i]->frame();
            frame_t frame2 = pls[j]->frame();

            int f1_left = std::min(frame1.x1, frame1.x2);
            int f1_right = std::max(frame1.x1, frame1.x2);
            int f1_bottom = std::min(frame1.y1, frame1.y2);
            int f1_top = std::max(frame1.y1, frame1.y2);

            int f2_left = std::min(frame2.x1, frame2.x2);
            int f2_right = std::max(frame2.x1, frame2.x2);
            int f2_bottom = std::min(frame2.y1, frame2.y2);
            int f2_top = std::max(frame2.y1, frame2.y2);

            int intersect_left = std::max(f1_left, f2_left);
            int intersect_right = std::min(f1_right, f2_right);
            int intersect_bottom = std::max(f1_bottom, f2_bottom);
            int intersect_top = std::min(f1_top, f2_top);

            if (intersect_left < intersect_right && intersect_bottom < intersect_top) {
                double intersection_area = (intersect_right - intersect_left) * (intersect_top - intersect_bottom);
                if (intersection_area > max_intersection_area) {
                    max_intersection_area = intersection_area;
                    max_i = i;
                    max_j = j;
                    found = true;
                }
            }
        }
    }
    if (!found) {
        return nullptr;
    }

    Planar ***result = new Planar**[2];
    result[0] = &pls[max_i];
    result[1] = &pls[max_j];
    return result;
}

void free_intersection_result(Planar ***result) {
    delete[] result;
}
