#include "task1.hpp"
#include "task2.hpp"

int main(int argc, char *argv[])
{
  if(argc != 2) {
    std::cerr << "Expected task number.";
    return 1;
  }
  try {
    int variant = std::stoi(argv[1]);
    switch(variant) {
    case 1:
      task1(std::cin, std::cout);
      break;
    case 2:
      task2(std::cin, std::cout);
      break;
    default:
      std::cerr << "Exprected number 1 or 2  as the task number." << std::endl;
      return 1;
    }
  } catch(const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 2;
  }

  return 0;
}
