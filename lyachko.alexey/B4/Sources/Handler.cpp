#include "../Headers/Handler.hpp"

Handler::Handler()
{
  Handler phonebook_;
  std::list<ElementWrapper> bookmarks_;
}

Handler::Handler(PhoneBook & phonebook) :
  phonebook_(phonebook)
{
  std::list<ElementWrapper> bookmarks_;
}

bool Handler::verifyName(std::string &line)
{
  if ((line.front() != '\"') || (line.back() != '\"'))
  {
    return false;
  }
  line.erase(std::remove(line.begin(), line.end(), '\\'), line.end());
  line.erase(0,1);
  line.pop_back();

  return true;
}

bool Handler::verifyNumber(std::string &line)
{
  if ( (!std::isdigit(line[0])) && (line[0] != '-') && (line[0]!= '+') )
    return false;
  if ((line.length() == 1) && !std::isdigit(line[0]))
    return false;
  else if ((line.length() == 1) && std::isdigit(line[0]))
    return true;
  for (size_t i = 1; i < line.length(); i++)
    if (!isdigit(line[i]))
      return false;
  return true;
}

bool Handler::checkBookmark(std::string &name) const
{
  for (auto elem: bookmarks_)
  {
    if (elem.getCurrentName() == name)
     return true;
  }
  return false;
}

std::list<ElementWrapper>::iterator Handler::getBookmark(std::string &bookmarksName)
{
    ElementWrapper temp(bookmarksName);
    std::list<ElementWrapper>::iterator findIter = std::find(bookmarks_.begin(), bookmarks_.end(), temp);
    return findIter;
}

void Handler::move(std::ostream &os, std::string &name, std::string &elementShift)
{
  if (phonebook_.empty())
  {
    os << "<EMPTY>" << std::endl;
    return ;
  }
  if (this->checkBookmark(name))
  {
    if (verifyNumber(elementShift))
    {
      auto mark = getBookmark(name);
      if ( ( (mark->getCurrentNumber() + std::stoi(elementShift)) >= phonebook_.size() ) || (mark->getCurrentNumber() + std::stoi(elementShift) < 0) )
      {
        os << "<INVALID COMMAND>" << std::endl;
        return ;
      }
      mark->shiftElement(std::stoi(elementShift));
    } else if ((elementShift == "first") || (elementShift == "last"))
    {
        auto mark = getBookmark(name);
        if (elementShift == "first")
        {
            mark->setCurrentElement(phonebook_.cbegin());
            mark->setCurrentNumber(0);
        } else if (elementShift == "last")
        {
            mark->setCurrentElement(std::next(phonebook_.end(),-1));
            mark->setCurrentNumber(phonebook_.size()-1);
        } else
            os << "<INVALID COMMAND>" << std::endl;
    } else
      os << "<INVALID COMMAND>" << std::endl;
  } else
    os << "<INVALID COMMAND>" << std::endl;
}

void Handler::store(std::ostream &os, std::string &cbookmark, std::string &nbookmark)
{
  if (this->checkBookmark(cbookmark))
  {
    ElementWrapper temp = *getBookmark(cbookmark);
    temp.setCurrentName(nbookmark);
    bookmarks_.push_back(temp);
  } else
    os << "<INVALID COMMAND>" << std::endl;
}

void Handler::push_back(std::ostream &os, std::string &number, std::string &name)
{
  if (verifyNumber(number) && (verifyName(name)))
  {
    Record record({number, name});
    if (phonebook_.empty())
    {
      phonebook_.push_back(record);
      ElementWrapper current("current");
      current.setCurrentElement(phonebook_.cbegin());
      bookmarks_.push_back(current);
    } else
    phonebook_.push_back(record);
  } else
    os << "<INVALID COMMAND>" << std::endl;
}

bool Handler::empty()
{
  return (phonebook_.empty());
}

void Handler::insert(std::ostream &os, std::string &bookmark, std::string &number, std::string &name, std::string &order)
{
  if ( (!this->verifyName(name)) || (!this->verifyNumber(number)) || 
       (!this->checkBookmark(bookmark)) || ((order != "before") && (order != "after")) )
  {
    os << "<INVALID COMMAND>" << std::endl;
    return ;
  }
  auto temp = getBookmark(bookmark);
  Record record({number, name});
  if (order == "after")
    phonebook_.insert(temp->getCurrentElement(), record, true);
  else
    phonebook_.insert(temp->getCurrentElement(), record, false);
}

void Handler::show(std::ostream &os, std::string &name)
{
  if (this->empty())
      os << "<EMPTY>" << std::endl;
  else
  {
      if (!this->checkBookmark(name))
          os << "<INVALID COMMAND>" << std::endl;
      else
        os << this->getBookmark(name)->getCurrentElement()->getNumber() << ' ' 
            << this->getBookmark(name)->getCurrentElement()->getName() << std::endl;
  } 
}

void Handler::deleteBookmark(std::ostream &os, std::string &name)
{
    if (!this->checkBookmark(name))
    {
      os << "<INVALID COMMAND>" << std::endl;
      return; 
    }else
    {
    auto temp = getBookmark(name);
    auto temp2 = temp->getCurrentElement();

    for (auto elem = bookmarks_.begin(); elem != bookmarks_.end(); elem++)
        if ( (elem->getCurrentElement() == temp2) && ((std::next(elem->getCurrentElement())) != phonebook_.end()) )
            elem->shiftElement(1);

    phonebook_.erase(temp2);
    }    
}
