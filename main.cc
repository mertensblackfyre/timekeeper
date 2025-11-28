#include "includes/parser.h"
#include "spdlog/spdlog.h"
#include <fmt/base.h>
#include <string>

int main(int argc, char **argv) {

  if (argc < 3) {
    spdlog::error("Usage: program <filename> <output filename>");
    return 1;
  }

  std::string input = argv[1];
  std::string output = argv[2];
  Parser parse(input);
  parse.parse_read_file();
  for (std::string ll : parse.commands) {
    if (helper_get_first_word(ll) == "push" ||
        helper_get_first_word(ll) == "pop") {

    
    }
  };
  return 0;
}
