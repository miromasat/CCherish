#include "CTerm.h"


CTerm::CTerm(string k)
  {
    key = k;
    data = data;
    left = right = nullptr;
    height = 1;
  }

CTerm::CTerm()
  {
    left = right = nullptr;
  }

unsigned char CTerm::getHeight(CTerm* p)
  {
    return (p) ? p->height : 0;
  }

int           CTerm::getBalanceFactor(CTerm* p)
  {
    return getHeight(p->right)-getHeight(p->left);
  }

void          CTerm::setHeight(CTerm* p)
  {
    unsigned char hl = getHeight(p->left);
    unsigned char hr = getHeight(p->right);
    p->height = (hl>hr?hl:hr)+1;
  }

CTerm*        CTerm::rotateRight(CTerm* p)
  {
    CTerm* q = p->left;
    p->left = q->right;
    q->right = p;
    setHeight(p);
    setHeight(q);
    return q;
  }

CTerm*        CTerm::rotateLeft(CTerm* q)
  {
    CTerm* p = q->right;
    q->right = p->left;
    p->left = q;
    setHeight(q);
    setHeight(p);
    return p;
  }

CTerm*        CTerm::balance(CTerm* p) // balancing the p node
  {
    setHeight(p);
    if( getBalanceFactor(p)==2 )
    {
        if( getBalanceFactor(p->right) < 0 )
            p->right = rotateRight(p->right);
        return rotateLeft(p);
    }
    if( getBalanceFactor(p)==-2 )
    {
        if( getBalanceFactor(p->left) > 0  )
            p->left = rotateLeft(p->left);
        return rotateRight(p);
    }
    return p; // balancing is not required
  }

CTerm*      CTerm::insert(CTerm* p, string k) // insert k key in a tree with p root
  {
      if( !p ) return new CTerm(k);
      if( k<p->key )
          p->left = insert(p->left, k);
      else
          p->right = insert(p->right, k);
      return balance(p);
  }

CTerm*        CTerm::findMin(CTerm* p) // find a node with minimal key in a p tree
  {
      return (p->left) ? findMin(p->left) : p;
  }

CTerm*        CTerm::removeMin(CTerm* p) // deleting a node with minimal key from a p tree
  {
      if( p->left==0 )
          return p->right;
      p->left = removeMin(p->left);
      return balance(p);
  }

CTerm*        CTerm::remove(CTerm* p, string k) // deleting k key from p tree
  {
      if( !p ) return 0;
      if( k < p->key )
          p->left = remove(p->left,k);
      else if( k > p->key )
          p->right = remove(p->right,k);
      else //  k == p->key
      {
          CTerm* q = p->left;
          CTerm* r = p->right;
          delete p;
          if( !r ) return q;
          CTerm* min = findMin(p);
          min->right = removeMin(p);
          min->left = q;
          return balance(min);
      }
      return balance(p);
  }


// int main()
// {
//   return 0;
// }
