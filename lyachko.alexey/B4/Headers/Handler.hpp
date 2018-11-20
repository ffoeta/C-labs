#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "PhoneBook.hpp"
#include "ElementWrapper.hpp"

class Handler
{
public:
  Handler();
  Handler(PhoneBook & phonebook);
  void insert(std::ostream &os, std::string &bookmark, std::string &number, std::string &name, std::string &order);
  void push_back(std::ostream &os, std::string &number, std::string &name);
  void store(std::ostream &os, std::string &cbookmark, std::string &nbookmark);
  void show(std::ostream &os, std::string &name);
  void move(std::ostream &os, std::string &name, std::string &elementShift);
  std::list<ElementWrapper>::iterator getBookmark(std::string &bookmarksName);
  void deleteBookmark(std::ostream &os, std::string &name);
  bool checkBookmark(std::string &name) const;
  bool verifyName(std::string &line);
  bool verifyNumber(std::string &line);
  bool empty();
  int size();


private:
  PhoneBook phonebook_;
  std::list<ElementWrapper> bookmarks_;
};


#endif
