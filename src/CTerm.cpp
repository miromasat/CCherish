#include "CTerm.h"
#include <algorithm>
#include <iostream>

using namespace std;

template <class T>
AVLnode<T>::AVLnode(T k, AVLnode *p) {
  key = k;
  balance = 0;
  parent = p;
  left = right = NULL;
}

template <class T>
AVLnode<T>::~AVLnode<T>() {
          delete left;
          delete right;
}
