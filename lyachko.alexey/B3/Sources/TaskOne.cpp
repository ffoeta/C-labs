#include "../Headers/TaskOne.hpp"

std::string divideString(std::string &str)
{
  std::string result;
  int count = 0;
  for (char elem: str)
  {
    if (elem == ' ')
      break;
    result.push_back(elem);
    count++;
  }
  str.erase(str.begin(), str.begin() + count + 1);
  return result;
}

ElementPriority getPriority(std::string &str)
{
  if (str == "HIGH")
    return ElementPriority::HIGH;
  else if (str == "NORMAL")
    return ElementPriority::NORMAL;
  else if (str == "LOW")
    return ElementPriority::LOW;
  else
    return LOWUP;
}


void task1(std::istream &is, std::ostream &os)
{
  std::string result = "";
  QueueWithPriority<std::string> queue;
  std::string line;

  while (is)
  {
    std::getline(is,line);

    if (line == "")
      continue;

    if (line == "get")
      {
        queue.GetElementFromQueue(result);
        if (result != "")
          os << result << std::endl;
        else
          os << "EMPTY"<< std::endl;
        result.clear();
      }
    else if (line == "accelerate")
      queue.Accelerate();
    else
    {
      std::string command = divideString(line);
      if (command != "add")
        os << "INVALID COMMAND" << std::endl;
      else
      {
        auto item = divideString(line);
        auto temp_str = divideString(line);
        auto priority = getPriority(temp_str);
        if ( (priority == ElementPriority::LOWUP) || (item == "") || (item == " ") )
          os << "INVALID COMMAND" << std::endl;
        else
          queue.PutElementToQueue(QueueElement<std::string>(item, priority));
      }
    }
    line.clear();
  }
}
