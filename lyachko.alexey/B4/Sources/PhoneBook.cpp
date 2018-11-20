#include "../Headers/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
  std::list<Record>::const_iterator current_;
  std::list<Record> book_;
}

std::list<Record>::iterator PhoneBook::get()
{
  return current_;
}

std::list<Record>::iterator PhoneBook::begin()
{
  return book_.begin();
}

std::list<Record>::const_iterator PhoneBook::cbegin()
{
  return book_.cbegin();
}

std::list<Record>::iterator PhoneBook::end()
{
  return book_.end();
}

std::list<Record>::const_iterator PhoneBook::cend()
{
  return book_.cend();
}

void PhoneBook::next()
{
  if (current_number_ + 1 >= int(book_.size()))
    throw std::length_error("Error: \n Record doesn't exist.");
  std::advance(this->current_,1);
  current_number_++;
}

void PhoneBook::prev()
{
  if (current_number_ - 1 < 0)
    throw std::length_error("Error: \n Record doesn't exist.");
  std::advance(this->current_,-1);
  current_number_--;
}

void PhoneBook::insert(Record record, bool order)
{
  if (book_.empty())
  {
    book_.push_back(record);
    current_ = book_.begin();
  } else
  if (order)
    book_.insert(std::next(current_), record);
  else
    book_.insert(current_, record);
}

void PhoneBook::insert(std::list<Record>::const_iterator it, Record record, bool order)
{
  if (book_.empty())
  {
    book_.push_back(record);
    current_ = book_.begin();
  } else 
  if (order)
    book_.insert(std::next(it), record);
  else 
    book_.insert(it, record);
}

void PhoneBook::replace(Record record)
{
  this->current_->setNumber(record.getNumber());
  this->current_->setName(record.getName());
}

void PhoneBook::push_back(Record record)
{
  if (book_.empty())
  {
    book_.push_back(record);
    current_ = book_.begin();
  } else
  book_.push_back(record);
}

void PhoneBook::move(int shift)
{
  if ((current_number_ + shift > int(book_.size())) || (current_number_ + shift) < 0)
    throw std::length_error("Error: \n Record doesn't exist.");
  std::advance(current_, shift);
  current_number_ += shift;
}

int PhoneBook::size()
{
  return book_.size();
}

bool PhoneBook::empty()
{
  return book_.empty();
}

void PhoneBook::erase(std::list<Record>::const_iterator &it)
{
  auto temp = book_.begin();
  for (auto elem = book_.begin(); elem != book_.end(); elem++)
    if (elem == it)
    {
      temp = elem;
      break;
    }
  book_.erase(temp);
}

  

