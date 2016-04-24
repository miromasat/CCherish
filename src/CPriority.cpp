#include "CPriority.h"

template <class T>
CPriority<T>::CPriority(T k, float p)
{
  key = k;
  priority = p;
}

template <class T>
CPriority<T>::~CPriority<T>()
{

}
