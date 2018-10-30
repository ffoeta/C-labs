#include "../Headers/sortx3.hpp"

void lyachko::sortx3(std::istream& is, std::ostream& os, const std::string& direction)
{
  if (!((direction == "ascending") || (direction == "descending")))
  {
    throw std::invalid_argument("Error:\n Wrong direction.");
  }

  std::vector<int> vec;

  bool dir = false;
  if (direction == "ascending") dir = true;

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

    sort(vec1, Brackets<std::vector<int>>(), dir);
    sort(vec2, At<std::vector<int>>(), dir);
    sort(mylist, Iterator<std::forward_list<int>>(), dir);
    print(vec1, os, " ", true);
    print(vec2, os, " ", true);
    print(mylist, os, " ");
  }
};
