#include <cstdio>
#include <cinttypes>
#include <string>
#include <vector>

#define CHARSET_SZ 128

bool isUniqueChars(const std::string &str) {
  if (str.length() > CHARSET_SZ) return false;

  std::vector<bool> char_set(CHARSET_SZ);
  for (std::size_t i = 0; i < str.length(); i++) {
    std::uint8_t val = str[i];
    if (val >= CHARSET_SZ) {
      fprintf(stderr, "Invalid char <%" PRIu8 ">\n", val);
    } else if (char_set[val]) { // Already found this char in string
      return false;
    }
    char_set[val] = true;
  }
  return true;
}
