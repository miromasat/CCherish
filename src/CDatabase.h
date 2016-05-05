#ifndef __CDatabase_h__
#define __CDatabase_h__

#include "CPriorityHeap.h"
#include "CTermTree.h"

template <class T>
class CDatabase {
public:
    CDatabase(int s);
    ~CDatabase(void);

    bool    insert    (T key, float priority);
    T       deleteKey (const T key);
    T       search    (const T key);
    void    display   ();
private:
    int size;
    int index;
    CTermTree<T>      DTree;
    CPriorityHeap<T>  PTree;
};
#endif
