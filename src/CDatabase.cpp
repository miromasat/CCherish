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
  cout << "<<<INSERT :k:" << key << ":p:" << priority << ":>>>"<< endl;
  if (index > size)
  {
    T res = PTree.deleteMin();
    DTree.deleteKey(res);
    index--;
  }
  PTree.insert(key, priority);
  DTree.insert(key);
  index++;
  return true;
}

template <class T>
T CDatabase<T>::deleteKey(const T key)
{
  cout << "<<<DELETE :k:" << key << ":>>>" << endl;
  T res;
  if (index < 1)
    return res;

  bool s = DTree.search(key);
  if (s == true) {
    PTree.deleteKey(key);
    DTree.deleteKey(key);

    index--;
  }

  return key;
}

template <class T>
void CDatabase<T>::display()
{
  cout << ">>>>>>>>>>>>>DB" << endl;
  PTree.printHeap();
  DTree.printInOrder();
  cout << "DB>>>>>>>>>>>>>" << endl;
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
