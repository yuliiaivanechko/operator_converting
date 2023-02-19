#include "car.h"
#include "point.h"
#include "print.h"
#include "scores.h"
#include "string.h"
#include <memory>

double add(double a, double b) { return a + b; }
int main() {

  CU::string str("Yuliia");
  str.insert(4, "Hi");
  std::cout << str << std::endl;
  str.erase(3, 2);
  CU::string str1("Your wellcome");
  std::cout << str << std::endl;
  std::cout << CU::compare(str, str1) << std::endl;
  str.append('T');
  std::cout << str << std::endl;
  return 0;
}