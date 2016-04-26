#include <string>
#include "CDatabase.h"

template <class T>
CDatabase<T>::CDatabase(int s)
{
  size = s;
  index = 0;
}

template <class T>
CDatabase<T>::~CDatabase<T>(void)
{
}

template <class T>
bool CDatabase<T>::insert(T key, float priority)
{
  if (index > size)
    return false;
  PTree.insert(key, priority);
  DTree.insert(key);

  index++;
  return true;
}

template <class T>
T CDatabase<T>::deleteKey(const T key)
{
  T res;
  if (index < 1)
    return res;

  PTree.deleteKey(key);
  DTree.deleteKey(key);
  return key;
}

template <class T>
void CDatabase<T>::display()
{
  PTree.printHeap();
  DTree.printInOrder();
}
