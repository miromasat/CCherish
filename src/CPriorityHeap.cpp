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
T CPriorityHeap<T>::deleteKey(const T key)
{
  T res;

  for(typename vector< CPriority<T> >::iterator it = heap.begin(); it != heap.end(); ++it) {
    if (key == it->key)
        {
          T delKey = it->key;

          it->key       = heap.back().key;
          it->priority  = heap.back().priority;

          heap.pop_back();
          index--;

          bubbleDown(it - heap.begin());
          return delKey;
        }

  }

  return res;
}

template <class T>
bool CPriorityHeap<T>::bubbleUp(int i) {
  int p = floor(i/2);

  while (p >= 0)
  {
    if (heap[i].priority < heap[p].priority)
    {
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

template <class T>
int CPriorityHeap<T>::minChild(int i) {
  int cl = i*2, cr = cl+1;

  if (cr > index - 1)
    return cl;
  else
  {
    if (heap[cl].priority < heap[cr].priority)
      return cl;
    else
      return cr;
  }


  return i;
}

template <class T>
bool CPriorityHeap<T>::bubbleDown(int i) {
  int c = minChild(i);

  while (c < index)
  {
    if (heap[i].priority > heap[c].priority)
    {
      CPriority<T> temp(heap[c].key, heap[c].priority);

      heap[c].priority = heap[i].priority;
      heap[c].key = heap[i].key;

      heap[i].priority = temp.priority;
      heap[i].key = temp.key;
    }else break;

    i = c;
    c = minChild(i);
  }
  return true;
}
