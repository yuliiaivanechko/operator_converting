#include "point.h"
#include <cassert>
#include <cmath>

point::point(double x, double y) : m_x{x}, m_y{y} {}

void point::print_info() {
  std::cout << "point\t" << this->m_x << '\t' << this->m_y << '\n';
}

double point::length() const { return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2)); }

// point point::operator+(const point &p) {
//   return point{m_x + p.m_x, m_y + p.m_y};
// }

point operator+(const point &p1, const point &p2) {
  return point{p1.m_x + p2.m_x, p1.m_y + p2.m_y};
}

double &point::operator[](size_t index) {
  assert(index == 0 || index == 1);
  return index == 0 ? m_x : m_y;
}