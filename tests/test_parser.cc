#include "../includes/parser.h"
#include <gtest/gtest.h>

TEST(Parser, ParserInstructions) {
  EXPECT_EQ(Parser::parse_instruction("M=D       // RAM[1] = the sum"), "M=D");
  EXPECT_EQ(Parser::parse_instruction("M=D+1       // Hello   "), "M=D+1");
  EXPECT_EQ(Parser::parse_instruction("@LOOP      // goto LOOP "), "@LOOP");
  EXPECT_EQ(Parser::parse_instruction("    0;JMP"), "0;JMP");
  EXPECT_EQ(Parser::parse_instruction("AM= A+1  // AA"), "AM=A+1");
  EXPECT_EQ(Parser::parse_instruction(" @R1"), "@R1");
}
