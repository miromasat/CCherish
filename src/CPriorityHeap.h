#ifndef __CPriorityHeap_h__
#define __CPriorityHeap_h__

#include <vector>
/* CPriorityHeap class describes BinaryHeap structure that holds a vector of nodes - CPriority */
template <class T>
class CPriorityHeap {
public:
    CPriorityHeap(int s);
    ~CPriorityHeap(void);

    bool    insert(T key);
    void    deleteKey(const T key);
    T       findMin();
private:
    vector<T> heap;
    float minPriority;
    int size;
    int index;
};
#endif
