#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "./PhoneBook.hpp"
#include <string>
#include <map>
#include <iostream>
#include <algorithm>

class Handler
{
public:
  Handler();
  Handler(const Handler &rhs);
  Handler &operator=(const Handler &rhs);
  void push_back(const PhoneBookEntry &entry);
  void store(const std::string &currentBookmark, const std::string &newBookmark);
  void show(const std::string &bookmark);
  void next(const std::string &bookmark);
  void prev(const std::string &bookmark);
  void insertBefore(const std::string & bookmark, const PhoneBookEntry &entry);
  void insertAfter(const std::string & bookmark, const PhoneBookEntry &entry);
  void moveTab(const std::string &bookmark, const int shift);
  void moveTab(const std::string &bookmark, const std::string &position);
  void removeEntry(const std::string &bookmark);
  void replaceEntry(const std::string &bookmark, const PhoneBookEntry &entry);

private:
  typedef std::map<std::string, PhoneBook::iterator> bookmark_type;
  PhoneBook book_;
  bookmark_type bookmarks_;

  bookmark_type::iterator getIterator(const std::string &bookmark);
  void insert(const std::string &bookmark, const PhoneBookEntry &entry, const bool after);
};

#endif
