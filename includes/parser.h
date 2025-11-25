#pragma once

#include "helper.h"
#include "spdlog/spdlog.h"
#include <fmt/base.h>
#include <fstream>
#include <iostream>
#include <string_view>

class Parser {

public:
  std::string line;
  std::ifstream input_file;

  Parser(const std::string &file_name) {
    input_file.open(file_name);
    if (!input_file.is_open())
      spdlog::error("Error opening file");
  }

  inline void parser_read_file();
  static inline void parser_memory_commands();

  ~Parser() {
    if (input_file.is_open())
      input_file.close();
  }
};

void Parser::parser_read_file() {
  while (std::getline(input_file, line)) {
    std::string l = helper_get_word(line);
    if (helper_get_word(line) == "push" || helper_get_word(line) == "pop") {
      parser_memory_commands();
    }
  };
};

void Parser::parser_memory_commands() { fmt::println("Momo"); };
