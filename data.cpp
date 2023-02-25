#include "car.h"
#include "comp_string.h"
#include "item.h"
#include "number.h"
#include "point.h"
#include "print.h"
#include "scores.h"
#include "string.h"
#include <memory>
#include <utility>

double add(double a, double b) { return a + b; }
int main() {
  comp_string s1("dog");
  comp_string s2("huy");

  std::cout << (s1 == s2) << std::endl;

  return 0;
}