#include "./Headers/text.hpp"

int main(int argc, char * argv[])
{
  unsigned long width_of_line = 40;

  if(argc > 1)
  {
    if (argc != 3)
    {
      std::cerr << "Error: \n Invalid number of arguments." << std::endl;
      return 1;
    }
    if (std::string(argv[1]) != "--line-width")
    {
      std::cerr  << "Error: \n Invalid 1st argument." << std::endl;
      return 1;
    }
    if (atoi(argv[2]) < 24)
    {
      std::cerr << "Error: \n Width lower than 24." << std::endl;
      return 1;
    }
    else 
    width_of_line = atoi(argv[2]);
  }

  try
  {
    Text text(std::cin, std::cout, width_of_line);
    text.outprint();
  }
  catch(std::invalid_argument &err)
  {
    std::cerr << err.what();
    return 1;
  }
  catch(std::exception &err)
  {
    std::cerr << err.what();
    return 2;
  }

  return 0;
}
