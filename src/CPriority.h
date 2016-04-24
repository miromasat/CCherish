#ifndef __CPriority_h__
#define __CPriority_h__
/* CPriority class describes a node in a BinaryHeap structure - CPriorityHeap */
template <class T>
class CPriority {
public:
    T key;
    float priority;

    CPriority(T k, float p);
    ~CPriority();
};
#endif
