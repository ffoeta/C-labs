#include "./Headers/TaskOne.hpp"
#include "./Headers/TaskTwo.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Error\n Exprected 2 parameters";
    return 1;
  }

  try
  {
    switch (atoi(argv[1])) {
    case 1:
      task1(std::cin, std::cout);
      break;
    case 2:
      task2(std::cin, std::cout);
      break;
    default:
      std::cerr << "Error\n Exprected 1 or 2 as 2nd parameter";
      return 1;
    }
  } catch (const std::invalid_argument &err) {
    std::cerr << err.what() << '\n';
    return 1;
  } catch (const std::exception &err) {
    std::cerr << err.what() << '\n';
    return 2;
  }

  return 0;
}
