#include <string>

using namespace std;

struct CTerm
{
    int                           key;
    unsigned char                 height;
    string                        data;
    CTerm*                        left;
    CTerm*                        right;
    //construct, destruct
                  CTerm           (int k, string d);
                  //~CTerm          ();
    //methods
    unsigned char getHeight       (CTerm* p);
    void          setHeight       (CTerm* p);
    int           getBalanceFactor(CTerm* p);
    CTerm*        balance         (CTerm* p);
    CTerm*        rotateRight     (CTerm* p);
    CTerm*        rotateLeft      (CTerm* p);
    CTerm*        insert          (CTerm* p, int k, string data);
    CTerm*        findMin         (CTerm* p);
    CTerm*        removeMin       (CTerm* p);
    CTerm*        remove          (CTerm* p, int k);
};
