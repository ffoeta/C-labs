#include "../Headers/sortx3.hpp"

void lyachko::sortx3(std::istream& is, std::ostream& os, const std::string& direction)
{
  if (!((direction == "ascending") || (direction == "descending"))) 
  {
    throw std::invalid_argument("Error:\n Wrong direction.");
  }

  std::vector<int> vec;

  bool dir = false;
  if (direction == "ascending")
  {
    dir = true;
  }
  else if (direction == "descending")
  {
    dir = false;
  }

  int temp = 0;
  
  is >> temp;
  while (!is.eof())
  {
    if (is.bad() || is.fail())
    {
      throw std::invalid_argument("Error:\n Input stream failed.");
    }
    vec.push_back(temp);
    is >> temp;
  }

  if (!vec.empty())
  {
    std::vector<int> vec1(vec), vec2(vec);

    std::forward_list<int> mylist(vec.begin(), vec.end());

    sort(vec1, getByBrackets, dir);
    sort(vec2, getByAt, dir);
    sort(mylist, getByIterator, dir);
    print(vec1, os, " ", true);
    print(vec2, os, " ", true);
    print(mylist, os, " ");
  }
};
