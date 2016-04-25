#include "CPriorityHeap.h"

#include <vector>
#include <math.h>

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
bool CPriorityHeap<T>::insert(T key, float priority)
{
  if (index > size)
    return false;

  CPriority<T> temp(key, priority);
  heap.push_back( temp );

  bubbleUp(index);
  index++;



  return true;
}

template <class T>
T CPriorityHeap<T>::findMin()
{
  return heap[0];
}

template <class T>
void CPriorityHeap<T>::printHeap() {

    for(typename vector< CPriority<T> >::iterator it = heap.begin(); it != heap.end(); ++it)
      cout << it->priority << "-" << it->key << " ,";

    cout << endl;
}

template <class T>
void CPriorityHeap<T>::deleteKey(const T key)
{
  for(typename vector<T>::iterator it = heap.begin(); it != heap.end(); ++it) {
    if (key.key == it.key)
      if (key.priority == it.priority)
        {
          heap.erase(it);
          index--;
        }

  }
}

template <class T>
bool CPriorityHeap<T>::bubbleUp(int i) {
  int p = floor(i/2);

  while (p >= 0)
  {
    if (heap[i].priority < heap[p].priority)
    {
      //cout << "X" << endl;
      CPriority<T> temp(heap[p].key, heap[p].priority);

      heap[p].priority = heap[i].priority;
      heap[p].key = heap[i].key;

      heap[i].priority = temp.priority;
      heap[i].key = temp.key;
    }else break;

    i = p;
    p = floor(i/2);
  }
  return true;
}
