#include <algorithm>
#include <iterator>
#include <functional>

#include "stat.hpp"

int main()
{
  try {
    Stat statistic;
    std::for_each(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::ref(statistic));
    if (!std::cin.eof())
      throw std::invalid_argument("Input Failed!");
    std::cout << statistic;
  }catch (std::exception& ex) {
    std::cerr << ex.what() << std::endl;
  }
  return 0;
}
