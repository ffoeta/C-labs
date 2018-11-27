#include "../Headers/DataStruct.hpp"
#include <sstream>
#include <istream>

size_t parseNum(const std::string & str, int& dest)
{
  size_t delim = str.find_first_of(',');
  if (delim == std::string::npos)
  {
    throw std::logic_error("Exprected be two ','.");
  }
  size_t pos = 0;
  dest = std::stoi(str.substr(0, delim), &pos);
  if (pos != delim)
  {
    throw std::logic_error("Wrong number");
  }
  if (dest < -5 || dest>5)
  {
    throw std::logic_error("Both keys must be in range if [-5;5]");
  }
  return delim;
}

void readVector(std::vector<DataStruct>& arr, std::istream & is)
{
  std::string line;
  DataStruct temp;
  while (std::getline(is, line))
  {
    line = line.substr(parseNum(line, temp.key1) + 1);
    temp.str = line.substr(parseNum(line, temp.key2) + 1);
    while (isspace(temp.str.front()))
    {
      temp.str.erase(0, 1);
    }
    arr.push_back(temp);
  }
}


bool DataStruct::operator<(const DataStruct &rhs) const
{
  if (rhs.key1 > key1)
  {
    return true;
  }
  if (rhs.key1 == key1)
  {
    if (rhs.key2 == key2)
    {
      if (rhs.str.size() == str.size())
      {
        return (rhs.str < str);
      }
      return (rhs.str.size() < str.size());
    }
    return (rhs.key2 > key2);
  }
  return false;
}

void sortVector(std::vector<DataStruct>& arr)
{
  std::sort(arr.begin(), arr.end());
}

void printVector(const std::vector<DataStruct>& arr, std::ostream & os)
{
  for (auto i:arr)
  {
    os << i.key1 << "," << i.key2 << "," << i.str << std::endl;
  }
}
