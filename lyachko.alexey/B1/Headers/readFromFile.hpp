#ifndef READFROMFILE
#define READFROMFILE

#include <fstream>
#include <memory>
#include "printSort.hpp"

namespace lyachko
{
  void readFromFile(const std::string& fileName, std::ostream& os);
}

#endif
