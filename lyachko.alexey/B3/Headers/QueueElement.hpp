#ifndef QUEUEELEMENT_HPP
#define QUEUEELEMENT_HPP

enum ElementPriority
{
  LOW,
  NORMAL,
  LOWUP,
  HIGH
};

template<typename T>
struct QueueElement
{
  QueueElement(T new_element, ElementPriority new_priority);
  T element;
  ElementPriority priority;
};

template<typename T>
QueueElement<T>::QueueElement(T new_element, ElementPriority new_priority) :
  element(new_element), priority(new_priority)
{
}


#endif
