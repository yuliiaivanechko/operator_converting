#pragma once
#include <cassert>
#include <iostream>
#include <string>

class scores {

public:
  scores() = delete;

  scores(const std::string &c) : course{c} {}

  void print_info() const {
    std::cout << course << " ";
    for (size_t i{}; i != 20; ++i) {
      std::cout << m_scores[i] << " ";
    }
    std::cout << '\n';
  }

  double &operator[](size_t index) {
    assert(index < 20 && index >= 0);
    return m_scores[index];
  }

  const double &operator[](size_t index) const {
    assert(index < 20 && index >= 0);
    return m_scores[index];
  }

private:
  std::string course{};
  double m_scores[20]{};
};