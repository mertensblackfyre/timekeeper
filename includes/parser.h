#pragma once

#include "helper.h"
#include "spdlog/spdlog.h"
#include <fmt/base.h>
#include <fstream>
#include <iostream>
#include <string_view>

struct Memory {
  std::string view;
  std::string command;
  std::string destination;
};

class Parser {
public:
  std::string line;
  std::ifstream input_file;

  Parser(const std::string &file_name) {
    input_file.open(file_name);
    if (!input_file.is_open())
      spdlog::error("Error opening file");
  }

  inline void parse_read_file();
  static inline void parse_memory_commands();
  static inline std::string parse_instruction(std::string_view line);
  ~Parser() {
    if (input_file.is_open())
      input_file.close();
  }
};

void Parser::parse_read_file() {
  while (std::getline(input_file, line)) {
    std::string l = helper_get_first_word(line);
    if (helper_get_first_word(line) == "push" ||
        helper_get_first_word(line) == "pop") {
      parse_memory_commands();
    }
  };
};
std::string Parser::parse_instruction(std::string_view line) {

  std::string parsed_string = "";
  for (const char &ch : line) {
    if (ch == '/')
      break;
    if (!std::isspace(ch) && ch != '/')
      parsed_string += ch;
  };

  return parsed_string;
}
void Parser::parse_memory_commands() { fmt::println("Momo"); };
