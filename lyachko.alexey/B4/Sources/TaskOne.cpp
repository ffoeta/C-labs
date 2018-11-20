#include "../Headers/TaskOne.hpp"

std::string divideString(std::string &str)
{
  std::string result = "";
  int count = 0;
  for (char elem: str)
  {
    if (elem == ' ')
      break;
    result.push_back(elem);
    count++;
  }
  if ( result.size() == str.size() )
    str.clear();
  else
    str.erase(str.begin(), str.begin() + count + 1);
  return result;
}


void taskOne(std::istream &is, std::ostream &os)
{

  PhoneBook book;
  Handler handler(book);

  std::string line;

  while (is)
  {
    std::getline(is,line);

    if (line == "")
      continue;

    std::string command = divideString(line);
    
    if (command == "add")
    {
      std::string number = divideString(line);
      handler.push_back(os, number, line);
    }else if (command == "store")
    {
      std::string bookmark = divideString(line);
      handler.store(os, bookmark, line);
    }else if (command == "insert")
    {
      std::string order = divideString(line);
      std::string bookmark = divideString(line);
      std::string number = divideString(line);
      handler.insert(os, bookmark, number, line, order);
    }else if (command == "delete")
    {
      handler.deleteBookmark(os, line);
    }else if (command == "show")
    {
      handler.show(os, line);
    }else if (command == "move")
    {
      std::string bookmark = divideString(line);
      handler.move(os, bookmark, line);
    }else
    {
      os << "<INVALID COMMAND>" << std::endl;
    }

    line.clear();
  }
}
