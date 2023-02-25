#include "car.h"
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
  point p1{3.5, 5.6};
  point p2{7.6, 8.9};
  std::cout << std::boolalpha;
  std::cout << (p1 < p2) << std::endl;
  std::cout << (p2 < p1) << std::endl;
  std::cout << (p1 == p2) << std::endl;
  std::cout << (p1 <= p2) << std::endl;
  return 0;
}