#include <iostream>
#include "gtest/gtest.h"

bool isUniqueChars(const std::string &str);

TEST(IsUniqueChars, Empty) { EXPECT_EQ(true, isUniqueChars("")); }

TEST(IsUniqueChars, Unique) { EXPECT_EQ(true, isUniqueChars("abcd")); }

TEST(IsUniqueChars, Duplicated) { EXPECT_EQ(false, isUniqueChars("abcda")); }

TEST(IsUniqueChars, OnlyRepetable) { EXPECT_EQ(false, isUniqueChars("aaaa")); }
