#include "includes/parser.h"
#include "spdlog/spdlog.h"
#include <string>

int main(int argc, char **argv) {

  if (argc < 2) {
    spdlog::error("Usage: program <filename> <output filename>");
    return 1;
  }

  std::string input = argv[1];
  // std::string output = argv[2];

  Parser parse(input);
  parse.parse_read_file();
  return 0;
}
