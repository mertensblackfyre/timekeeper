#include "../includes/helper.h"
#include <array>
#include <cctype>
#include <string>
#include <string_view>

std::string helper_get_first_word(std::string_view line) {
  std::string word = "";
  for (const char ch : line) {
    if (!std::isspace(ch))
      word += ch;
    else
      break;
  };
  return word;
};

std::array<std::string, 3> helper_get_words(std::string_view line) {
  std::array<std::string, 3> words = {};
  int p = 0;
  for (const char ch : line) {
    std::string word = "";
    if (!std::isspace(ch)) {
      word += ch;
    } else {
      words[p++] = word;
      word.erase();
    }
  };
  return words;
};
