#include "number.h"
#include <iostream>

class item {
public:
  item() = default;
  item(int i) : a{i}, b{i}, c{i} {}
  item(int a_p, int b_p, int c_p) : a{a_p}, b{b_p}, c{c_p} {}
  auto operator<=>(const item &i) const = default;

  auto operator<=>(int n) const { return (a <=> n); }

private:
  int a{1};
  int b{2};
  int c{3};
  number n{};
};