#include "../includes/helper.h"
#include <gtest/gtest.h>

TEST(Helper, HelperGetWords) {
  EXPECT_EQ(helper_get_first_word("push constant 17"), "push");
  EXPECT_EQ(helper_get_first_word("pop temp 12"), "pop");
  EXPECT_EQ(helper_get_first_word("add"), "add");
  EXPECT_EQ(helper_get_first_word("lt"), "lt");
};
