#include "task1.hpp"

void task1(std::istream &in, std::ostream &out)
{
  std::unordered_set<std::string> words;
  std::copy(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>(), std::inserter(words, words.begin()));
  std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(out, "\n"));
}
