#include <algorithm>
#include "./RecordType.hpp"

class PhoneBook
{
public:
  PhoneBook();
  std::list<Record>::iterator get();
  std::list<Record>::iterator begin();
  std::list<Record>::const_iterator cbegin();
  std::list<Record>::iterator end();
  std::list<Record>::const_iterator cend();
  void insert(Record record, bool order);
  void insert(std::list<Record>::const_iterator it, Record record, bool order);
  void push_back(Record record);
  void replace(Record record);
  void erase(std::list<Record>::const_iterator &it);
  void move(int shift);
  void next();
  void prev();
  bool empty();
  int size();
private:
  std::list<Record>::iterator current_;
  int current_number_;
  std::list<Record> book_;
};
