

#include <cctype>
#include <string>
#include <string_view>

std::string helper_get_first_word(std::string_view line) {

  std::string word = "";
  for (const char ch : line) {
    if (!std::isspace(ch))
      word += ch;
  };
  return word;
};
