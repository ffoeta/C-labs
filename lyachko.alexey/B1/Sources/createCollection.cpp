#include "../Headers/createCollection.hpp"

void lyachko::createCollection(std::istream& is, std::ostream& os)
{
  std::vector<int> vec;
  int buffer = 0;
  while (is && !(is >> buffer).eof())
  {
    if (is.bad() || is.fail())
    {
      throw std::invalid_argument("Error:\n Input failed.");
    }
    if (buffer == 0)
    {
      break;
    }
    else
    {
      vec.push_back(buffer);
    }
  }

  if (buffer != 0)
  {
    throw std::invalid_argument("Error:\n Input had to end with 0.");
  }

  if (vec.empty()) {
    return;
  }

  if (vec.back() == 1)
  {
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
      if (*it % 2 == 0)
      {
        it--;
        vec.erase(it + 1);
      }
    }
  }
  else if (vec.back() == 2)
  {
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
      if (*it % 3 == 0)
      {
        it = vec.insert(it + 1, 3, 1) + 2;
      }
    }
  }

  if (!vec.empty()) {
    print(vec, os, " ");
  }

};
