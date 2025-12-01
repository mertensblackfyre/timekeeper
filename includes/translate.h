#pragma once

#include "helper.h"
#include "parser.h"
#include "spdlog/spdlog.h"
#include <algorithm>
#include <array>
#include <fmt/base.h>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

using fmt::print;
using fmt::println;

class Translator {
private:
  std::ofstream output_file;
  std::unordered_map<std::string, std::string> memory_commands_reference = {
      {"push", "@SP\nM=M+1\n"},    {"pop", "@SP\nM=M-1\n"},
      {"dest", "@SP\nA=M\nD=M\n"}, {"num", "\nD=A\n"},
      {"local", "@LCL\nM=M+"},     {"argument", "@ARGS\nM=M+"},
  };

public:
  Translator(const std::string &file_name) {
    output_file.open(file_name, std::ios::app);
    if (!output_file.is_open())
      spdlog::error("Error opening file");
  }

  inline void translate_memory_commands(ParserMemory command);
  inline void translate_append_file(std::string_view line);

  ~Translator() {
    if (output_file.is_open())
      output_file.close();
  };
};

void Translator::translate_append_file(std::string_view line) {
  if (output_file.is_open()) {
    output_file << line;
  } else {
    spdlog::error("Error opening file for appending");
  }
  return;
};

void Translator::translate_memory_commands(ParserMemory command) {
  print("{} ", command.command);
  print("{} ", command.destination);
  println("{}", command.value);

  // Handle Value
  std::string value_asm =
      "@" + command.value + memory_commands_reference["num"];
  translate_append_file(value_asm);

  // Handle destination
  if (command.destination == "command") {
    std::string dest_asm = memory_commands_reference["dest"];
    translate_append_file(dest_asm);
  };
  // Handle command
  std::string cmd_asm = memory_commands_reference[command.command];
  translate_append_file(cmd_asm);
};
