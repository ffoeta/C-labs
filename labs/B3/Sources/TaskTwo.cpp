#include "../Headers/TaskTwo.hpp"

void task2(std::istream &is, std::ostream &os)
{
  std::list<int> list_;
  int temp = 0;

  while (is)
  {
    if (is >> temp)
    {
      if (temp < 1 || temp > 20)
        throw std::invalid_argument("Error: \n Vulues should be from 1 to 20.");
      list_.push_back(temp);
      if (list_.size() > 20)
        throw std::invalid_argument("Error: \n Values overdone.");
    }
    else if (is.eof())
      break;
    else
      throw std::invalid_argument("Wrong argument");
  }
  while (list_.size() != 0)
  {
    os << *list_.begin() << ' ';
    list_.pop_front();
    list_.reverse();
  }
  os << std::endl;
}
