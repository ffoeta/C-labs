#include <iostream>
#include <string>
#include "part1.hpp"
#include "part2.hpp"
#include <stdexcept>

int main(int argc, char *argv[])
{
  if (argc != 2) {
    std::cerr << "Missing task number.";
    return 1;
  }
  try {
    switch(std::stoi(argv[1])) {
    case 1:
      part1(std::cin, std::cout);
      break;
    case 2:
      part2(std::cin, std::cout);
      break;
    default:
      std::cerr << "The wrong task.";
      return 1;
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 2;
  }
  return 0;
}
