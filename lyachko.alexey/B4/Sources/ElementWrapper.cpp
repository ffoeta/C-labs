#include "../Headers/ElementWrapper.hpp"

ElementWrapper::ElementWrapper() :
  name(""), current_number(0), current_element()
{
}

ElementWrapper::ElementWrapper(std::string new_name) :
  name(new_name), current_number(0), current_element()
{
}

ElementWrapper::ElementWrapper(const ElementWrapper & elementWrapper)
{
  this->name = elementWrapper.name;
  this->current_element = elementWrapper.current_element;
  this->current_number = elementWrapper.current_number;
}

bool ElementWrapper::operator == (const ElementWrapper &elementWrapper) const 
{ 
  return this->name == elementWrapper.name;
}

void ElementWrapper::shiftElement(int elementShift)
{
    this->current_number += elementShift;
    std::advance(this->current_element, elementShift);
}

int ElementWrapper::getCurrentNumber() const
{
    return this->current_number;
}

std::string ElementWrapper::getCurrentName() const
{
    return this->name;
}

std::list<Record>::const_iterator ElementWrapper::getCurrentElement() const
{
    return this->current_element;
}

void ElementWrapper::setCurrentElement(std::list<Record>::const_iterator iterator)
{
    this->current_element = iterator;
}

void ElementWrapper::setCurrentName(std::string name)
{
    this->name = name;
}

void ElementWrapper::setCurrentNumber(int number)
{
    this->current_number = number;
}
