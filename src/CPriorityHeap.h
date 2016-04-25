#ifndef __CPriorityHeap_h__
#define __CPriorityHeap_h__

#include <vector>
#include "CPriority.h"
/* CPriorityHeap class describes BinaryHeap structure that holds a vector of nodes - CPriority */
template <class T>
class CPriorityHeap {
public:
    CPriorityHeap(int s);
    ~CPriorityHeap(void);

    bool    insert(T key, float priority);
    void    deleteKey(const T key);
    void    printHeap();
    T       findMin();
private:
    vector< CPriority<T> > heap;
    float minPriority;
    int size;
    int index;
};
#endif
