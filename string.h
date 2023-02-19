#pragma once
#include <cassert>
#include <cstring>
#include <iostream>
namespace CU {

class string {
  friend std::ostream &operator<<(std::ostream &out, const CU::string &s);
  friend string operator+(const string &left, const string &right);
  friend string &operator+=(string &left, const string &right);

public:
  string(const char *data, size_t size = 15) {
    m_size = size;
    m_data = new char[m_size];
    std::strcpy(m_data, data);
  }

  void clear() {
    this->m_size = 0;
    delete[] this->m_data;
  }

  friend int compare(const string &str1, const string &str2);

  void erase(size_t index, size_t number) {
    assert(number <= m_size - index);
    memmove(m_data + index, m_data + index + number, m_size - index - number);
  }

  void append(char ch) {
    assert(strlen(m_data) < m_size);
    m_data[strlen(m_data)] = ch;
  }

  int insert(size_t pos, const string &str) {
    if ((pos + strlen(str.m_data)) >= m_size)
      return -1;
    memmove(m_data + pos + strlen(str.m_data), m_data + pos, strlen(m_data));
    memcpy(m_data + pos, str.c_str(), strlen(str.m_data));
    return 0;
  }

  // Copy constructor
  string(const string &source) {
    m_size = source.m_size;
    m_data = new char[m_size]; // We want to do deep copy here.
    std::strcpy(m_data, source.m_data);
  }

  // Copy assignment operator
  string &operator=(const string &right_operand) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &right_operand) {
      delete[] m_data;
      m_data = new char[right_operand.m_size];
      std::strcpy(m_data, right_operand.m_data);
    }
    return *this;
  }

  const char *c_str() const { return m_data; }

  ~string() {
    delete[] m_data;
    m_data = nullptr;
  }

private:
  unsigned int m_size;
  char *m_data{nullptr};
};

inline std::ostream &operator<<(std::ostream &out, const CU::string &s) {
  out << s.m_data;
  return out;
}

inline string operator+(const string &left, const string &right) {
  string tmp(left);
  tmp += right;
  return tmp;
}

inline string &operator+=(string &left, const string &right) {
  std::strcat(left.m_data, right.m_data);
  return left;
}

inline int compare(const string &str1, const string &str2) {
  return std::strncmp(str1.m_data, str2.m_data, str1.m_size);
}

} // namespace CU