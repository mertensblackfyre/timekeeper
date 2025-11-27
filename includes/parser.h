#pragma once

#include "helper.h"
#include "spdlog/spdlog.h"
#include <fmt/base.h>
#include <fstream>
#include <iostream>
#include <string_view>

struct ParserMemory {
  std::string value{};
  std::string command{};
  std::string destination{};
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
  static inline ParserMemory parse_memory_commands(std::string_view line);
  static inline std::string parse_instruction(std::string_view line);

  ~Parser() {
    if (input_file.is_open())
      input_file.close();
  };
};

void Parser::parse_read_file() {
  while (std::getline(input_file, line)) {
    std::string ll = parse_instruction(line);
    if (helper_get_first_word(ll) == "push" ||
        helper_get_first_word(ll) == "pop") {
      parse_memory_commands(ll);
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
};

ParserMemory Parser::parse_memory_commands(std::string_view line) {
  ParserMemory cmd = {"", "", ""};
  std::array<std::string, 3> words = helper_get_words(line);

  if (words[0] == "push" || words[0] == "pop")
    cmd.command = words[0];

  cmd.destination = words[1];
  cmd.value = words[2];
  return cmd;
};
