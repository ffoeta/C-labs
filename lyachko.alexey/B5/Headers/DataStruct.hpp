#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

struct DataStruct
{
  int key1;
  int key2;
  std::string str;
  bool operator<(const DataStruct & elem) const;
};

void readVector(std::vector<DataStruct> & arr, std::istream &is);
void sortVector(std::vector<DataStruct> &arr);
void printVector(const std::vector<DataStruct> & arr, std::ostream &os);

#endif //DATA_STRUCT_HPP

