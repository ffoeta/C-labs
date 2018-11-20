#include "../Headers/RecordType.hpp"

Record::Record() :
 number(""),  name("")
{
}

Record::Record(std::string new_number, std::string new_name)
{
  this->number = new_number;
  this->name = new_name;
}

Record::Record(const Record& record)
{
  this->number = record.number;
  this->name = record.name;
}

void Record::setNumber(std::string number)
{
  this->number = number;
}

void Record::setName(std::string name)
{
  this->name = name;
}

std::string Record::getNumber() const
{
  return this->number;
}

std::string Record::getName() const
{
  return this->name;
}
