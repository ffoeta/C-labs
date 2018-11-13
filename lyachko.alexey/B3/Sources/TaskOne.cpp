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

ElementPriority getPriority(std::string &str)
{
  if (str == "high")
    return ElementPriority::HIGH;
  else if (str == "normal")
    return ElementPriority::NORMAL;
  else if (str == "low")
    return ElementPriority::LOW;
  else
    return ElementPriority::NONE;
}

void task1(std::istream &is, std::ostream &os)
{
  QueueElement<std::string> result;
  QueueWithPriority<std::string> queue;
  std::string line;

  while (is)
  {
    std::getline(is,line);

    if (line == "")
      continue;

    if (line == "get")  
    {
      queue.getElementFromQueue(result);
      if (result.validate())
        os << result.element << std::endl;
      else
        os << "<EMPTY>"<< std::endl;
      result.clear();
    }
    else if (line == "accelerate")
      queue.accelerate();
    else
    {
      std::string command = divideString(line);
      if (command != "add")
        os << "<INVALID COMMAND>" << std::endl;
      else
      {
        auto temp_str = divideString(line);
        auto priority = getPriority(temp_str);
        auto item = line;
        
        if ( (priority == ElementPriority::NONE) || (item == "") || (item == " ") )
          os << "<INVALID COMMAND>" << std::endl;
        else
          queue.putElementToQueue(priority, item);
      }
    }
    line.clear();
  }
}
