#ifndef __CTerm_h__
#define __CTerm_h__
template <class T>
class CTerm {
public:
    T key;
    int balance;
    CTerm *left, *right, *parent;

    CTerm(T k, CTerm *p);
    ~CTerm();
};
#endif
