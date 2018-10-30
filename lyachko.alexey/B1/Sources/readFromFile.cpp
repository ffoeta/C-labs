#include "../Headers/readFromFile.hpp"

void  lyachko::readFromFile(const std::string& inputFile, std::ostream& os)
{

  std::ifstream file(inputFile);

  if (!file) throw std::invalid_argument("Error:\n Cannot open " + inputFile);

  file.seekg(0, file.end);
  auto size = file.tellg();
  file.seekg(0, file.beg);

  std::vector<char> vec(size);
  file.read(vec.data(), size);
  lyachko::print(vec, os, "");

  file.close();

}
