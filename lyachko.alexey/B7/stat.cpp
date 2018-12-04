#include "stat.hpp"

Stat::Stat() :
  summary_(DEFAULT_INT_VALUE), max_(MIN_INT_VALUE), 
  min_(MAX_INT_VALUE), first_(DEFAULT_INT_VALUE),
  positive_(DEFAULT_INT_VALUE), negative_(DEFAULT_INT_VALUE),
  odd_sum_(DEFAULT_INT_VALUE), even_sum_(DEFAULT_INT_VALUE), 
  equals_(false)
{}

void Stat::operator()(int num)
{
  summary_++;
  if (num > max_)
    max_ = num;
  if (num < min_)
    min_ = num;
  if (num > 0)
    positive_++;
  if (num < 0)
    negative_++;
  if (summary_ == 0)
    first_ = num;
  if (num % 2 == 0) 
    even_sum_ += num;
  else 
    odd_sum_ += num;
  if (first_ == num) 
    equals_ = true;
  else
    equals_ = false;
}

std::ostream & operator<<(std::ostream & stream , const Stat & stats)
{
  if (stats.summary_ == 0) {
    stream << "No Data" << std::endl;
    return stream;
  }
  stream << "Max: " << stats.max_ << std::endl;
  stream << "Min: " << stats.min_ << std::endl;
  stream << "Mean: " << static_cast<long double>((stats.even_sum_ + stats.odd_sum_)) / stats.summary_ << std::endl;
  stream << "Positive: " << stats.positive_ << std::endl;
  stream << "Negative: " << stats.negative_ << std::endl;
  stream << "Odd Sum: " << stats.odd_sum_ << std::endl;
  stream << "Even Sum: " << stats.even_sum_ << std::endl;
  stream << "First/Last Equal: ";
  stream << (stats.equals_ ? "yes" : "no");
  stream << std::endl;

  return stream;
}

