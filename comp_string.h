#include <iostream>
#include <string>

class comp_string {
public:
  comp_string() = default;

  comp_string(const std::string &str) : m_str{str} {}

  std::weak_ordering operator<=>(const comp_string &right) const {
    if (this->m_str.size() == right.m_str.size()) {
      return std::weak_ordering::equivalent;
    } else if (this->m_str.size() < right.m_str.size()) {
      return std::weak_ordering::less;
    } else {
      return std::weak_ordering::greater;
    }
  }

  bool operator==(const comp_string &right) const {
    return (this->m_str.size() == right.m_str.size());
  }

private:
  std::string m_str{};
};