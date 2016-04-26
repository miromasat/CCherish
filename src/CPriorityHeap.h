#ifndef __CPriorityHeap_h__
#define __CPriorityHeap_h__

#include <vector>
#include "CPriority.h"
/* CPriorityHeap class describes BinaryHeap structure that holds a vector of nodes - CPriority */
template <class T>
class CPriorityHeap {
public:
    CPriorityHeap();
    ~CPriorityHeap(void);

    bool    insert(T key, float priority);
    T       deleteKey(const T key);
    T       deleteMin();
    void    printHeap();
    T       findMin();
private:
    vector< CPriority<T> > heap;
    float minPriority;
    int index;

    bool    bubbleUp(int i);
    bool    bubbleDown(int i);
    int     minChild(int i);
};
#endif
