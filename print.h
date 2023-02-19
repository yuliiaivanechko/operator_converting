#pragma once
#include <iostream>

class print {

public:
  void operator()(const std::string &name) const {
    std::cout << name << std::endl;
  }

  std::string operator()(const std::string &f_name, const std::string &l_name) {
    return f_name + l_name;
  }
};

/*
compare()
append()*/
