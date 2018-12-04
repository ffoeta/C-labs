#ifndef STAT_HPP
#define STAT_HPP

#include <iomanip>
#include <iostream>
#include <limits>

const auto MAX_INT_VALUE = std::numeric_limits<int>::max();
const auto MIN_INT_VALUE = std::numeric_limits<int>::min();

class Stat
{
public:
  Stat();
  void operator()(int num);
  friend std::ostream& operator<<(std::ostream& stream, const Stat& stats);
private:
  unsigned int summary_;
  long long int max_;
  long long int min_;
  long long int first_;
  unsigned int positive_;
  unsigned int negative_;
  long long int odd_sum_;
  long long int even_sum_;
  bool equals_;
};

#endif
