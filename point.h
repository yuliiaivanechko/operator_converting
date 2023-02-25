#pragma once

#include <iostream>

class car;

class point {
public:
  point() = default;
  point(double x, double y);
  void print_info();
  friend point operator+(const point &p1, const point &p2);
  // point operator+(const point &p);
  friend std::ostream &operator<<(std::ostream &os, const point &p);
  friend std::istream &operator>>(std::istream &is, point &p);
  friend point &operator++(point &p);
  friend point operator++(point &p, int);

  point &operator=(const point &p);

  point &operator+=(const point &p2) {
    this->m_x += p2.m_x;
    this->m_y += p2.m_y;
    return *this;
  }

  point &operator=(car &c);

  explicit operator double() { return static_cast<double>(m_x); }
  double &operator[](size_t index);
  bool operator==(const point &p2) const;

  std::partial_ordering operator<=>(const point &p) const;

private:
  double length() const;
  double m_x{};
  double m_y{};
  double *data{};
};

inline std::ostream &operator<<(std::ostream &os, const point &p) {

  os << "point: " << p.m_x << " " << p.m_y << '\t' << p.length() << "\n";
  return os;
}

inline std::istream &operator>>(std::istream &is, point &p) {
  std::cout << "enter point: ";
  is >> p.m_x >> p.m_y;
  return is;
}
