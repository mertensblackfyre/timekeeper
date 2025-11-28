#pragma once

#include "helper.h"
#include "spdlog/spdlog.h"
#include <algorithm>
#include <array>
#include <fmt/base.h>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Translator {
  std::ifstream output_file;

  Translator(const std::string &file_name) {
    output_file.open(file_name);
    if (!output_file.is_open())
      spdlog::error("Error opening file");
  }

  std::string translate_memory_commands(std::string command);
  ~Translator() {
    if (output_file.is_open())
      output_file.close();
  };
};
