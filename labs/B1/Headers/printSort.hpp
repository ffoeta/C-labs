#ifndef PRINT_SORT_HPP
#define PRINT_SORT_HPP

#include <iostream>
#include <forward_list>
#include <vector>
#include <list>

namespace lyachko
{
  void fillRandom(double * array, int size) noexcept;

  template<typename Container>
    struct At
    {
      typedef typename Container::reference ref;

      size_t getBegin(const Container&)
      {
        return 0;
      }

      size_t getEnd(const Container& container)
      {
        return container.size();
      }

      ref getElement(Container& container, size_t i)
      {
        return container.at(i);
      }
    };

  template <typename Container>
    struct Iterator
    {
      typedef typename Container::reference ref;
      typedef typename Container::iterator iterator;

      iterator getBegin(Container& container)
      {
        return container.begin();
      }

      iterator getEnd(Container& container)
      {
        return container.end();
      }

      ref getElement(const Container&, iterator &it)
      {
        return *it;
      }
    };

  template< typename Container >
    struct Brackets
    {
      typedef typename Container::reference ref;

      size_t getBegin(const Container&)
      {
        return 0;
      }

      size_t getEnd(const Container& container)
      {
        return container.size();
      }

      ref getElement(Container& container, size_t i)
      {
        return container[i];
      }
    };


  template <typename Container, typename CallType>
  void sort(Container & collection, CallType callType, bool ascending) noexcept
  {
   for (auto it1 = callType.getBegin(collection); it1 != callType.getEnd(collection); it1++)
      for (auto it2 = it1; it2 != callType.getEnd(collection); it2++)
        if ((callType.getElement(collection, it1) > callType.getElement(collection, it2)) == ascending)
          std::swap(callType.getElement(collection, it1), callType.getElement(collection, it2));
  }

  template <typename T>
  void print(T & collection, std::ostream & stream, const std::string & sep, const bool nextline = false) noexcept
  {
    for (const auto & elem : collection)
      stream << elem << sep;
    if (nextline)
      stream << std::endl;
  }
}

#endif
