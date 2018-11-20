#include "./Headers/TaskOne.hpp"
#include "./Headers/TaskTwo.hpp"

int main(int argc, char * argv[])
{
  if (argc < 2)
  {
    std::cerr << "Error: \n Too few arguments passed." << std::endl;
    return 1;
  }
  if ( ( atoi(argv[1]) > 2) || (atoi(argv[1]) <= 0 ) )
  {
    std::cerr << "Error: \n Wrong arguments passed." << std::endl;
    return 1;
  }

  try
  {
    if (atoi(argv[1]) == 1)
      taskOne(std::cin, std::cout);
    else
      taskTwo();

  } catch (const std::invalid_argument &err) {
    std::cerr << err.what() << std::endl;
    return 1;
  } catch (const std::exception &err) {
    std::cerr << err.what() << std::endl;
    return 2;
  }

  return 0;
}
