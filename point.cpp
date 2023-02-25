#include "point.h"
#include "car.h"
#include <cassert>
#include <cmath>

point::point(double x, double y) : m_x{x}, m_y{y}, data{new double(10)} {}

void point::print_info() {
  std::cout << "point\t" << this->m_x << '\t' << this->m_y << '\n';
}

double point::length() const { return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2)); }

// point point::operator+(const point &p) {
//   return point{m_x + p.m_x, m_y + p.m_y};
// }

point &point::operator=(car &c) {
  this->m_x = this->m_y = c.get_speed();
  return *this;
}

point operator+(const point &p1, const point &p2) {
  return point{p1.m_x + p2.m_x, p1.m_y + p2.m_y};
}

double &point::operator[](size_t index) {
  assert(index == 0 || index == 1);
  return index == 0 ? m_x : m_y;
}

point &operator++(point &p) {
  ++(p.m_x);
  ++(p.m_y);
  return p;
}

point operator++(point &p, int) {
  point local_copy{p};
  ++p;
  return local_copy;
}

point &point::operator=(const point &p) {
  if (this != &p) {
    delete this->data;
    this->data = new double(*p.data);
    this->m_x = p.m_x;
    this->m_y = p.m_y;
  }
  return *this;
}

bool point::operator==(const point &p2) const {
  return this->length() == p2.length();
}

std::partial_ordering point::operator<=>(const point &p) const {
  if (this->length() < p.length()) {
    return std::partial_ordering::less;
  } else if (this->length() == p.length()) {
    return std::partial_ordering::equivalent;
  } else if (this->length() > p.length()) {
    return std::partial_ordering::greater;
  } else {
    return std::partial_ordering::unordered;
  }
}