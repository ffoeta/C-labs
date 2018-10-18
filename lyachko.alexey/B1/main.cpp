#include <stdexcept>

#include "./Headers/createCollection.hpp"
#include "./Headers/fillVector.hpp"
#include "./Headers/readFromFile.hpp"
#include "./Headers/sortx3.hpp"

int main(int argc, const char* argv[])
{
  try{
    if (argc < 2) {
      throw std::invalid_argument("Error:\n B1 requires arguments.");
    }
    switch ( atoi(argv[1]) ) {
    case 1: 
      if (argc != 3) {
        throw std::invalid_argument("Error:\n Expected 3 parameters for sortx3.");
      } else { 
        lyachko::sortx3(std::cin, std::cout, argv[2]); 
      } break;
    case 2: 
      if (argc != 3) {
        throw std::invalid_argument("Error:\n Expected 3 parameters for readFromFile.");
      } else { 
        lyachko::readFromFile(argv[2], std::cout); 
      } break;
    case 3: 
      if (argc != 2) {
        throw std::invalid_argument("Error:\n Expected 2 parameters for createCollection.");
      } else { 
        lyachko::createCollection(std::cin, std::cout);
      } break;
    case 4: 
      if (argc != 4) {
        throw std::invalid_argument("Error:\n Expected 4 parameters for fillVector.");
      } else { 
        lyachko::fillVector(std::cout, atoi(argv[3]), argv[2]);
      } break;
    }
  }
  catch (std::invalid_argument& ex)
  {
    std::cerr << ex.what() << std::endl;
    return 1;
  }
  catch (std::exception& ex)
  {
    std::cerr << ex.what() << std::endl;
    return 1;
  }
  catch(...)
  {
    std::cerr << "Error:\n Unknown" << std::endl;
    return 1;
  }

  return 0;
}
