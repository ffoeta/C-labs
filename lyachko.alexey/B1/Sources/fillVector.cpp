#include "../Headers/fillVector.hpp"
  
static double fRand(double fMin, double fMax) noexcept 
{
  double f = static_cast<double>(rand()) / RAND_MAX;
  return fMin + f * (fMax - fMin);
}

void lyachko::fillRandom(double * array, int size) noexcept 
{
  for (int i = 0; i < size; i++)
  {
    array[i] = fRand(-1.0, 1.0);
  }
}

void lyachko::fillVector(std::ostream &os, size_t size, const std::string &direction)
{
  if (direction != "ascending" &&
      direction != "descending") {
    throw std::invalid_argument("Error: wrong direction of the sorting!");
  }

  auto dir = false;
  if (direction == "ascending") 
  {
    dir = true;
  }
  else if (direction == "descending") 
  {
    dir = false;
  }

  std::vector<double> buf_vec(size);
  fillRandom(buf_vec.data(), size);
  lyachko::print(buf_vec, os, " ", true);

  lyachko::sort(buf_vec, getByBrackets, dir);
  lyachko::print(buf_vec, os, " ", true);
}
