#include "CPriorityHeap.h"

#include <vector>

template <class T>
CPriorityHeap<T>::CPriorityHeap(int s)
{
  size = s;
  index = 0;
}

template <class T>
CPriorityHeap<T>::~CPriorityHeap<T>(void)
{
  heap.erase(heap.begin(), heap.end());
  size = index = 0;
}


template <class T>
bool CPriorityHeap<T>::insert(T key)
{
  heap.push_back(key);
  index++;

  if (index <= size)
    return true;

  return false;
}

template <class T>
T CPriorityHeap<T>::findMin()
{
  return heap[0];
}

template <class T>
void CPriorityHeap<T>::deleteKey(const T key)
{
  for(typename vector<T>::iterator it = heap.begin(); it != heap.end(); ++it) {
    if (key.key == it.key)
      if (key.priority == it.key)
        heap.erase(it);
  }
}
