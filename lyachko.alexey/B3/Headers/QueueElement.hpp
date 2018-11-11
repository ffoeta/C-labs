#ifndef QUEUEELEMENT_HPP
#define QUEUEELEMENT_HPP

enum ElementPriority
{
  NONE,
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
  void invalidate();
  bool validate() const;
  void clear();
  bool valid;
  T element;
  ElementPriority priority;
};

template<typename T>
QueueElement<T>::QueueElement()
{
  priority = ElementPriority::NONE;
  valid = true;
}

template<typename T>
QueueElement<T>::QueueElement(T new_element, ElementPriority new_priority) :
  element(new_element), priority(new_priority)
{
  valid = true;
}

template<typename T>
QueueElement<T>::QueueElement(const QueueElement & queueelement)
{
  this->element = queueelement.element;
  this->priority = queueelement.priority;
  this->valid = queueelement.valid;
}

template<typename T>
void QueueElement<T>::clear()
{
  element.clear();
  valid = true;
  priority = ElementPriority::NONE;
}

template<typename T>
void QueueElement<T>::invalidate()
{
  valid = false;
}

template<typename T>
bool QueueElement<T>::validate() const
{
  return this->valid;
}

#endif
