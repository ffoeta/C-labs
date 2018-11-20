#ifndef CONTAINER_OF_FACTORIALS_HPP
#define CONTAINER_OF_FACTORIALS_HPP

#include <iterator>

const size_t FACTORIAL_INDEX_BEGIN = 1;
const size_t FACTORIAL_INDEX_END = 11;
const size_t FACTORIAL_OF_1 = 1;
const size_t FACTORIAL_OF_11 = 39916800;

class ContainerOfFactorials
{
public:
  class Iterator;
  ContainerOfFactorials() = default;
  Iterator begin() const;
  Iterator end() const;
};

class ContainerOfFactorials::Iterator : public std::iterator<std::bidirectional_iterator_tag, size_t>
{
public:
  Iterator(const Iterator &other) = default;

  const size_t *operator->() const;
  const size_t &operator*() const;

  Iterator& operator ++();
  Iterator operator++(int);
  Iterator& operator--();
  Iterator operator--(int);
    
  Iterator& operator=(const Iterator &object) = default;
  bool operator==(const Iterator& ite) const;
  bool operator!=(const Iterator& ite) const;
private:
  size_t index_;
  size_t value_;

  Iterator(size_t index, size_t value);

  friend class ContainerOfFactorials;
};

#endif // CONTAINER_OF_FACTORIALS_HPP
