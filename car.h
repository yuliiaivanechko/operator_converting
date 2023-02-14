#pragma once
#include <iostream>

class car {
public:
  car() = default;

  car(std::string str, double sp) : m_color{str}, m_speed{sp} {}

  std::string get_color() { return m_color; }

  double get_speed() { return m_speed; }

private:
  std::string m_color;
  double m_speed;
};