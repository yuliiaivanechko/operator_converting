#pragma once
#include <iostream>

class number {

  friend std::ostream &operator<<(std::ostream &os, number &n);

public:
  number() = default;
  number(int var) : m_wrapped{var} {}

  int get_int() const;

  friend bool operator<(const number &n, const number &n1);

  auto operator<=>(const number &n) const = default;

private:
  int m_wrapped{};
};

inline std::ostream &operator<<(std::ostream &os, number &n) {
  os << n.m_wrapped << std::endl;
  return os;
}
inline bool operator<(const number &n, const number &n1) {
  return n.m_wrapped < n1.m_wrapped;
}