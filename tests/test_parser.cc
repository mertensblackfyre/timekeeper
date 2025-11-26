#include "../includes/parser.h"
#include <gtest/gtest.h>

TEST(Parser, ParserInstructions) {
  EXPECT_EQ(Parser::parse_instruction("push segment 1 // Hello World"),
            "push segment 1");
  EXPECT_EQ(Parser::parse_instruction("  pop temp 2 "), "pop temp 2");
};
