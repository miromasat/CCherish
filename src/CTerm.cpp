#include "CTerm.h"
#include <algorithm>
#include <iostream>

using namespace std;

template <class T>
CTerm<T>::CTerm(T k, CTerm *p) {
  key = k;
  balance = 0;
  parent = p;
  left = right = NULL;
}

template <class T>
CTerm<T>::~CTerm<T>() {
          delete left;
          delete right;
}
