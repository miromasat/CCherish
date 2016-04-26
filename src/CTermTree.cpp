#include "CTerm.h"
#include "CTermTree.h"

#include <algorithm>
#include <iostream>

using namespace std;

/* AVL class definition */
template <class T>
void CTermTree<T>::rebalance(CTerm<T> *n) {
    setBalance(n);

    if (n->balance == -2) {
        if (height(n->left->left) >= height(n->left->right))
            n = rotateRight(n);
        else
            n = rotateLeftThenRight(n);
    }
    else if (n->balance == 2) {
        if (height(n->right->right) >= height(n->right->left))
            n = rotateLeft(n);
        else
            n = rotateRightThenLeft(n);
    }

    if (n->parent != NULL) {
        rebalance(n->parent);
    }
    else {
        root = n;
    }
}

template <class T>
CTerm<T>* CTermTree<T>::rotateLeft(CTerm<T> *a) {
    CTerm<T> *b = a->right;
    b->parent = a->parent;
    a->right = b->left;

    if (a->right != NULL)
        a->right->parent = a;

    b->left = a;
    a->parent = b;

    if (b->parent != NULL) {
        if (b->parent->right == a) {
            b->parent->right = b;
        }
        else {
            b->parent->left = b;
        }
    }

    setBalance(a);
    setBalance(b);
    return b;
}

template <class T>
CTerm<T>* CTermTree<T>::rotateRight(CTerm<T> *a) {
    CTerm<T> *b = a->left;
    b->parent = a->parent;
    a->left = b->right;

    if (a->left != NULL)
        a->left->parent = a;

    b->right = a;
    a->parent = b;

    if (b->parent != NULL) {
        if (b->parent->right == a) {
            b->parent->right = b;
        }
        else {
            b->parent->left = b;
        }
    }

    setBalance(a);
    setBalance(b);
    return b;
}

template <class T>
CTerm<T>* CTermTree<T>::rotateLeftThenRight(CTerm<T> *n) {
    n->left = rotateLeft(n->left);
    return rotateRight(n);
}

template <class T>
CTerm<T>* CTermTree<T>::rotateRightThenLeft(CTerm<T> *n) {
    n->right = rotateRight(n->right);
    return rotateLeft(n);
}

template <class T>
int CTermTree<T>::height(CTerm<T> *n) {
    if (n == NULL)
        return -1;
    return 1 + std::max(height(n->left), height(n->right));
}

template <class T>
void CTermTree<T>::setBalance(CTerm<T> *n) {
    n->balance = height(n->right) - height(n->left);
}

template <class T>
void CTermTree<T>::printBalance(CTerm<T> *n) {
    if (n != NULL) {
        printBalance(n->left);
        std::cout << n->balance << " ";
        printBalance(n->right);
    }
}

template <class T>
void CTermTree<T>::printInOrder(CTerm<T> *n) {
    if (n != NULL) {
        printInOrder(n->left);
        std::cout << n->key << ",";
        printInOrder(n->right);
    }
}

template <class T>
CTerm<T>* CTermTree<T>::findMin(CTerm<T> *n) {
    return (n->left) ? findMin(n->left) : n;
}

template <class T>
CTermTree<T>::CTermTree(void) : root(NULL) {}

template <class T>
CTermTree<T>::~CTermTree(void) {
    delete root;
}

template <class T>
bool CTermTree<T>::insert(T key) {
    if (root == NULL) {
        root = new CTerm<T>(key, NULL);
    }
    else {
        CTerm<T>
            *n = root,
            *parent;

        while (true) {
            if (n->key == key)
                return false;

            parent = n;

            bool goLeft = n->key > key;
            n = goLeft ? n->left : n->right;

            if (n == NULL) {
                if (goLeft) {
                    parent->left = new CTerm<T>(key, parent);
                }
                else {
                    parent->right = new CTerm<T>(key, parent);
                }

                rebalance(parent);
                break;
            }
        }
    }

    return true;
}

template <class T>
void CTermTree<T>::deleteKey(const T delKey) {
    if (root == NULL)
        return;

    CTerm<T>
        *n       = root,
        *parent  = root,
        *delNode = NULL,
        *child   = root;

    while (child != NULL) {
        parent = n;
        n = child;
        child = delKey >= n->key ? n->right : n->left;
        if (delKey == n->key)
            delNode = n;
    }

    if (delNode != NULL) {
        delNode->key = n->key;

        child = n->left != NULL ? n->left : n->right;

        if (root->key == delKey) {
            root = child;
        }
        else {
            if (parent->left == n) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }

            rebalance(parent);
        }
    }
}

template <class T>
void CTermTree<T>::printBalance() {
    printBalance(root);
    std::cout << std::endl;
}

template <class T>
void CTermTree<T>::printInOrder() {
    printInOrder(root);
    std::cout << std::endl;
}

template <class T>
T CTermTree<T>::findMin() {
    CTerm<T> *minKey = findMin(root);
    return minKey->key;
}

template <class T>
bool CTermTree<T>::search(const T delKey) {
    if (root == NULL)
        return false;

    CTerm<T>
        *n        = root,
        *parent   = root,
        *findNode = NULL,
        *child   = root;

    while (child != NULL) {
        parent = n;
        n = child;
        child = delKey >= n->key ? n->right : n->left;
        if (delKey == n->key)
            return true;
    }

}
