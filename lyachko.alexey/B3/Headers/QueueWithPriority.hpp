#ifndef QUEUEWITHPRIORITY_HPP
#define QUEUEWITHPRIORITY_HPP

#include "QueueElement.hpp"
#include <list>

template<typename Element_Type>
class QueueWithPriority
{
public:
  void PutElementToQueue(const ElementPriority priority, const Element_Type & item);
  void GetElementFromQueue(QueueElement<Element_Type> & result);
  void Accelerate() noexcept;
  int GetSize() noexcept;
  void sort();
private:
  std::list<QueueElement<Element_Type>> list_;
};


template <typename T>
bool comp(T & var1, T & var2)
{
  if (var1.priority > var2.priority)
    return true;
  return false;
}

template <typename Element_Type>
void QueueWithPriority<Element_Type>::PutElementToQueue(const ElementPriority priority, const Element_Type & item)
{
  std::list<QueueElement<Element_Type>> temp_list;
  QueueElement<Element_Type> temp(item, priority);
  temp_list.push_back(temp);
  list_.merge(temp_list, comp<QueueElement<Element_Type>>);
}

template <typename Element_Type>
void QueueWithPriority<Element_Type>::GetElementFromQueue(QueueElement<Element_Type> & result)
{
  if (list_.size() == 0)
  {
    result.invalidate();
    return ;
  }
    
  else
  {
    result = *list_.begin();
    list_.pop_front();
    return ;
  }
}

template <typename Element_Type>
void QueueWithPriority<Element_Type>::Accelerate() noexcept
{
  if (list_.size() == 0) 
    return ;

  std::list<QueueElement<Element_Type>> temp_list;

  for (auto elem = list_.begin(); elem != list_.end(); elem++)
    if (elem->priority == ElementPriority::LOW)
    {
      temp_list.push_back(*elem);
    }

  if ( temp_list.size() == 0 ) 
    return ;

  list_.remove_if([](QueueElement<Element_Type> element){ return element.priority == ElementPriority::LOW; });

  for (auto elem = temp_list.begin(); elem != temp_list.end(); elem++)
    elem->priority = ElementPriority::LOWUP;

  list_.merge(temp_list, comp<QueueElement<Element_Type>>);
}

template <typename Element_Type>
int QueueWithPriority<Element_Type>::GetSize() noexcept
{
  return list_.size();
}

#endif
