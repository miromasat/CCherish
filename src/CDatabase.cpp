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
  {
    T res = PTree.deleteMin();
    DTree.deleteKey(res);
    cout << "Key deleted: " << res << endl;
    DTree.printInOrder();
  }
  cout << "Key inserted: " << key << endl;
  PTree.insert(key, priority);
  DTree.insert(key);
  DTree.printInOrder();
  index++;
  return true;
}

template <class T>
T CDatabase<T>::deleteKey(const T key)
{
  cout << "Key deleted: " << key << endl;
  T res;
  if (index < 1)
    return res;

  PTree.deleteKey(key);
  DTree.deleteKey(key);
  index--;
  return key;
}

template <class T>
void CDatabase<T>::display()
{
  //PTree.printHeap();
  DTree.printInOrder();
}

template <class T>
T CDatabase<T>::search(const T key)
{
  bool s = DTree.search(key);

  if (!s)
  {
    insert(key, 1);
  }

  return key;
}
