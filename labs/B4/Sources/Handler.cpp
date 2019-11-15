#include "../Headers/Handler.hpp"

Handler::Handler()
{
  bookmarks_["current"] = book_.end();
}

Handler::Handler(const Handler &rhs)
{
  *this = rhs;
}

Handler &Handler::operator=(const Handler &rhs)
{
  if (this != &rhs)
  {
    book_ = rhs.book_;
    bookmarks_.clear();
    for (auto bmark : rhs.bookmarks_)
    {
      std::list<PhoneBookEntry>::const_iterator iter = bmark.second;
      bookmarks_[bmark.first] = std::next(book_.begin(), std::distance(rhs.book_.cbegin(), iter));
    }
  }
  return *this;
}

void Handler::replaceEntry(const std::string &bookmark, const PhoneBookEntry & entry)
{
  *(getIterator(bookmark)->second) = entry;
}

void Handler::show(const std::string &bookmark)
{
  auto iter = getIterator(bookmark);
  if (iter->second == book_.end())
  {
    std::cout << "<EMPTY>" << std::endl;
  }
  else
  {
    std::cout << iter->second->number << " " << iter->second->name << std::endl;
  }
}

void Handler::push_back(const PhoneBookEntry &entry)
{
  if (book_.empty())
  {
    book_.pushBack(entry);
    bookmarks_["current"] = book_.begin();
  }
  else
  {
    book_.pushBack(entry);
  }
}

void Handler::store(const std::string &currentBookmark, const std::string &newBookmark)
{
  auto iter = getIterator(currentBookmark);
  if (!bookmarks_.emplace(newBookmark, iter->second).second)
  {
    throw std::invalid_argument("This bookmark already exists");
  }
}

void Handler::insertBefore(const std::string &bookmark, const PhoneBookEntry & entry)
{
  insert(bookmark, entry, false);
}

void Handler::insertAfter(const std::string &bookmark, const PhoneBookEntry & entry)
{
  insert(bookmark, entry, true);
}

void Handler::insert(const std::string &bookmark, const PhoneBookEntry & entry, const bool after)
{
  if (book_.empty())
  {
    push_back(entry);
    return;
  }
  auto iter = getIterator(bookmark);
  if (iter->second != book_.end())
  {
    if (!after)
    {
      book_.insert(iter->second, entry);
    }
    else
    {
      book_.insert(std::next(iter->second), entry);
    }
  }
  else
  {
    book_.pushBack(entry);
  }
}

void Handler::removeEntry(const std::string &bookmark)
{
  auto iter = getIterator(bookmark);
  if (book_.empty() || iter->second == book_.end())
  {
    throw std::invalid_argument("Removing from empty PhoneBook");
  }
  auto current = iter->second;
  auto next = std::next(current);
  std::for_each(bookmarks_.begin(), bookmarks_.end(), [&](auto &mark)
  {
    if (mark.second == current) {
      mark.second = next;
    }
  });
  book_.erase(current);
  std::for_each(bookmarks_.begin(), bookmarks_.end(), [&](auto &mark)
  {
    if (mark.second == book_.end()) {
      mark.second = --book_.end();
    }
  });
}

void Handler::prev(const std::string &bookmark)
{
  moveTab(bookmark, -1);
}

void Handler::next(const std::string &bookmark)
{
  moveTab(bookmark, 1);
}

Handler::bookmark_type::iterator Handler::getIterator(const std::string &bookmark)
{
  auto iter = bookmarks_.find(bookmark);
  if (iter == bookmarks_.end())
  {
    throw std::invalid_argument("error");
  }
  return iter;
}

void Handler::moveTab(const std::string &bookmark, const int shift)
{
  auto iter = getIterator(bookmark);
  std::advance(iter->second, shift);
}

void Handler::moveTab(const std::string &bookmark, const std::string & position)
{
  auto iter = getIterator(bookmark);
  if (position != "first" && position != "last")
  {
    std::cout << "<INVALID STEP>" << std::endl;
    return;
  }
  if (book_.empty())
  {
    iter->second = book_.end();
    return;
  }
  if (position == "first")
  {
    iter->second = book_.begin();
  }
  else
  {
    iter->second = std::prev(book_.end());
  }
}
