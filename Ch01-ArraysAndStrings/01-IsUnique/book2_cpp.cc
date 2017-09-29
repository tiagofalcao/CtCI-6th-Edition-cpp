#include <cstdio>
#include <cinttypes>
#include <bitset>
#include <string>

#define CHARSET_SZ 128

bool isUniqueChars(const std::string &str) {
  std::bitset<CHARSET_SZ> bits(0);
  for (unsigned int i = 0; i < str.length(); i++) {
    std::uint8_t val = str[i];
    if (val >= CHARSET_SZ) {
      fprintf(stderr, "Invalid char <%" PRIu8 ">\n", val);
    } else if (bits.test(val)) {
      return false;
    }
    bits.set(val);
  }
  return true;
}
