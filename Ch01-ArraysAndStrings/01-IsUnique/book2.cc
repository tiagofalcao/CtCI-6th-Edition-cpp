#include <string>

bool isUniqueChars(const std::string &str) {
  int checker = 0;
  for (unsigned int i = 0; i < str.length(); i++) {
    int val = str[i] - 'a';
    if ((checker & (1 << val)) > 0) {
      return false;
    }
    checker |= (1 << val);
  }
  return true;
}
