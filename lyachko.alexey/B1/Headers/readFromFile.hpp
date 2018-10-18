#ifndef READFROMFILE
#define READFROMFILE

#include <fstream>
#include <memory>
#include "lib.hpp"

namespace lyachko
{
  void readFromFile(const std::string& fileName, std::ostream& os);
}

#endif
