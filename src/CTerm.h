#ifndef __CTerm_h__
#define __CTerm_h__
/* AVL node */
template <class T>
class AVLnode {
public:
    T key;
    int balance;
    AVLnode *left, *right, *parent;

    AVLnode(T k, AVLnode *p);
    ~AVLnode();
};
#endif
