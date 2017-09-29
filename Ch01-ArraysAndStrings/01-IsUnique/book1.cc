#include <string>
#include <vector>

bool isUniqueChars(const std::string &str) {
  if (str.length() > 128) return false;

  std::vector<bool> char_set(128);
  for (unsigned int i = 0; i < str.length(); i++) {
    int val = str[i];
    if (char_set[val]) { // Already found this char in string
      return false;
    }
    char_set[val] = true;
  }
  return true;
}
