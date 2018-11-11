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
  QueueElement();
  QueueElement(T new_element, ElementPriority new_priority);
  QueueElement(const QueueElement & queueelement);
  void clear();
  T element;
  ElementPriority priority;
};

template<typename T>
QueueElement<T>::QueueElement()
{
}

template<typename T>
QueueElement<T>::QueueElement(T new_element, ElementPriority new_priority) :
  element(new_element), priority(new_priority)
{
}

template<typename T>
QueueElement<T>::QueueElement(const QueueElement & queueelement)
{
  this->element = queueelement.element;
  this->priority = queueelement.priority;
}

template<typename T>
void QueueElement<T>::clear()
{
  element.clear();
  priority = ElementPriority::LOWUP;
}


#endif
