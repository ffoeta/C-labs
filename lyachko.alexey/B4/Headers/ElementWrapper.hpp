#ifndef ELEMENTWRAPPER_HPP
#define ELEMENTWRAPPER_HPP

#include "./RecordType.hpp"

class ElementWrapper
{
public:
  ElementWrapper();
  ElementWrapper(std::string name);
  ElementWrapper(const ElementWrapper & elementWrapper);
  void shiftElement(int shiftElement);
  int getCurrentNumber() const;
  std::string getCurrentName() const;
  std::list<Record>::const_iterator getCurrentElement() const;
  void setCurrentElement(std::list<Record>::const_iterator iterator);
  void setCurrentNumber(int number);
  void setCurrentName(std::string name);
  bool operator == (const ElementWrapper &elementWrapper) const;
private:
  std::string name;
  int current_number;
  std::list<Record>::const_iterator current_element;
};

#endif
