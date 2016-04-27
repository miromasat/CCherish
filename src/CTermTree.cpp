#include "CTerm.h"
#include "CTermTree.h"

#include <algorithm>
#include <iostream>

using namespace std;

/* AVL class definition */
template <class T>
void CTermTree<T>::rebalance(CTerm<T> *n) {
    setBalance(n);

    if (n == NULL) return;

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
    cout << "ROTATE LEFT" << endl;
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
    cout << "ROTATE RIGHT" << endl;
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
        std::cout << n->key << ":"<< &n << ",";
        printInOrder(n->right);
    }
}

template <class T>
void CTermTree<T>::renderInOrder(CTerm<T> *n, int level) {

    // int i;
    // if (n!=NULL)
    // {
    //     display(n->right, level + 1);
    //     printf("\n");
    //     if (n == root)
    //     cout<<"Root -> ";
    //     for (i = 0; i < level && ptr != root; i++)
    //         cout<<"        ";
    //     cout<<ptr->data;
    //     display(ptr->left, level + 1);
    // }

    if (n != NULL) {
        renderInOrder(n->right, level+1);
      // for (int i = 0; i < level; i++)
      //   cout<<"---";
        cout << endl;
        //cout << endl;
      for (int i = 0; i < level; i++)
        if (level > 1) cout<<"        ";
        cout << "->" << n->key;
        renderInOrder(n->left, level+1);
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

                //rebalance(parent);
                break;
            }
        }
    }

    return true;
}

template <class T>
CTerm<T>* CTermTree<T>::deleteKey2(CTerm<T> *r, T delKey){
  if(r == NULL) return r;
  else if(delKey < r->key) r->left  = deleteKey2(r->left,  delKey);
  else if(delKey > r->key) r->right = deleteKey2(r->right, delKey);
  else {
    //cout << "Nasiel som: " << delKey << endl;
    // Case 1: No Child
    if(r->left == NULL && r->right == NULL){
      //cout << "Deti nemal" << endl;
      delete r;
      r = NULL;
    // Case 2: one child
    } else if(r->left == NULL){
      //CTerm<T> *temp = r;
      r = r->right;
      rebalance(r);
      //delete temp;
      //cout << "Mal praveho syna" << endl;
    } else if(r->right == NULL){
      //CTerm<T> *temp = r;
      r = r->left;
      rebalance(r);
      //delete temp;
      //cout << "Mal laveho syna" << endl;
    } else{
      CTerm<T> *temp = findMin(r->right);
      //cout << "Mal oboch synov a nasledovnik je: " << temp->key << endl;
      r->key = temp->key;
      r->right = deleteKey2(r->right, temp->key);
    }

    //rebalance(r);


  }
  //rebalance(r);
  return r;
}

template <class T>
void CTermTree<T>::deleteKey3(const T delKey) {
  root = deleteKey2(root, delKey);
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
        {
            delNode = n;
        }
    }

    /*cout << "N = " << n->key;
    cout << ", PARENT = " << parent->key;
    cout << ", DELNODE = " << delNode->key << endl;*/
    //cout << ", CHILD = " << child->key << endl;

    if (delNode != NULL) {
        delNode->key = n->key;

        child = n->left != NULL ? n->left : n->right;
        //cout << "CHILD = " << child->key << endl;
        if (root->key == delKey) {
            //CTerm<T> * newRoot = child;
            root = child;
            cout << "WHOOP root " << endl;
        }
        else {
            if (parent->left == n) {
                delete parent->right;
                cout << "OLD" << parent->left;
                parent->left = child;
                cout << "; NEW" << parent->left << endl;
            }
            else {
                delete parent->left;
                cout << "OLD" << parent->right;
                parent->right = child;
                cout << "; NEW" << parent->right << endl;
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
void CTermTree<T>::renderInOrder() {
    renderInOrder(root, 1);
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
    return false;
}
