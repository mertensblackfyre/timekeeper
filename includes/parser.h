#pragma once

#include "helper.h"
#include "spdlog/spdlog.h"
#include <algorithm>
#include <array>
#include <cctype>
#include <fmt/base.h>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

struct ParserMemory {
  std::string value{};
  std::string command{};
  std::string destination{};
};

enum Type { MEMORY, LOGICAL };

class Parser {

private:
  std::string line;
  std::ifstream input_file;
  constexpr static std::array<std::string_view, 9> logical_commands = {
      "add", "sub", "neg", "eq", "gt", "lt", "and", "or", "not"};

public:
  std::vector<std::pair<int, std::string>> commands;
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
    std::string ll = line;
    if (helper_get_first_word(ll) == "push" ||
        helper_get_first_word(ll) == "pop") {
      std::pair<int, std::string> w = {MEMORY, ll};
      commands.emplace_back(w);
    } else {
      std::pair<int, std::string> w = {LOGICAL, ll};
      commands.emplace_back(w);
    }
  };
};

std::string Parser::parse_instruction(std::string_view line) {
  std::string parsed_string = "";
  int p = 0;

  while (std::isspace(line[p])) {
    p++;
  };
  /*
    while (p != line.size()) {
      char ch = line[p++];
      if (ch == '/')
        break;
      if (!std::isspace(ch) && ch != '/') {
        parsed_string += ch;
      } else {
        if (p + 1 == line.size()) {
          break;
        } else {

          parsed_string += " ";
        }
      }
    };
  */
  while (p != line.size()) {
    char ch = line[p++];
    if (ch == '/')
      break;
    while (!std::isspace(ch) && ch != '/') {
      parsed_string += ch;
    };

    parsed_string += " ";
  };
  fmt::println("{}", parsed_string);

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
