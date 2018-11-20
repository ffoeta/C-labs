#ifndef RECORDTYPE_HPP
#define RECORDTYPE_HPP

#include <iostream>
#include <string>
#include <list>

class Record
{
public:
  Record();
  Record(std::string new_number, std::string new_name);
  Record(const Record& record);
  void setNumber(std::string number);
  void setName(std::string number);
  std::string getNumber() const;
  std::string getName() const;

private:
  std::string number;
  std::string name;
};

#endif
