#include "../Headers/sortx3.hpp"

void lyachko::sortx3(std::istream& is, std::ostream& os, const std::string& direction)
{

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
  while (!is.eof() && is.good())
  {
    is >> temp;
    vec.push_back(temp);
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
