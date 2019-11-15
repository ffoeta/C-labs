#include "../Headers/TaskTwo.hpp"

void TaskTwo()
{
  ContainerOfFactorials container;

  std::copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  std::reverse_copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}
