#include "car.h"
#include "point.h"
#include "scores.h"
#include "string.h"
#include <memory>

double add(double a, double b) { return a + b; }
int main() {

  point p1{2.4, 5.6};
  car c{"red", 120.6};
  p1 = c;
  std::cout << p1;
  return 0;
}