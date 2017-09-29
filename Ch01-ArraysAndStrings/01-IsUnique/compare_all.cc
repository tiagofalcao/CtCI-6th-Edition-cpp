#include <string>

bool isUniqueChars(const std::string &str) {
  if (str.length() <= 1) return true;
  for (std::size_t i = 0; i < str.length(); i++) {
    for (std::size_t j = i + 1; j < str.length(); j++) {
      if (str[i] == str[j]) {
        return false;
      }
    }
  }
  return true;
}
