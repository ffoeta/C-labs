#ifndef LIB_HPP
#define LIB_HPP

#include <iostream>
#include <forward_list>
#include <vector>
#include <list>

namespace lyachko 
{
  void fillRandom(double * array, int size) noexcept;

  template <typename T>
  typename T::value_type getByBrackets(const T& item, const typename T::iterator& it) noexcept
  {
    long index = std::distance<typename T::const_iterator>(item.begin(), it);
    return item[index];
  }

  template <typename T>
  typename T::value_type getByAt(const T& item, const typename T::iterator& it) noexcept
  {
    long index = std::distance<typename T::const_iterator>(item.begin(), it);
    return item.at(index);
  }

  template <typename T>
  typename T::value_type getByIterator(const T&, const typename T::iterator& it) noexcept
  {
    return *it;
  }

  template <typename T>
  void sort(T& collection,
            typename T::value_type (&get_elem)(const T&, const typename T::iterator&),
            bool ascending) noexcept
  {
    using iter_type = typename T::iterator;

    for (iter_type it = collection.begin(); it != collection.end(); ++it)
    {
      for (iter_type it1 = std::next(it); it1 != collection.end(); ++it1)
      {
        if ( (get_elem(collection, it) > get_elem(collection, it1)) == ascending )
        {
          std::swap(*it, *it1);
        }
      }
    }
  };

  template <typename T>
  void print(T& collection, std::ostream& stream, const std::string& separator, bool new_line = false) noexcept
  {
    for (const auto& elem : collection)
    {
      stream << elem << separator;
    }
    if (new_line)
    {
      stream << std::endl;
    }
  };
}

#endif
