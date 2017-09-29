#include <algorithm>
#include <string>

bool isUniqueCharsModify(std::string &str) {
  if (str.length() <= 1) return true;
  std::sort(str.begin(), str.end());
  for (std::size_t i = 1; i < str.length(); i++) {
    if (str[i-1] == str[i]) {
      return false;
    }
  }
  return true;
}

bool isUniqueChars(const std::string &str) {
  std::string s = std::string(str);
  return isUniqueCharsModify(s);
}
