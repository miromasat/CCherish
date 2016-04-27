#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "./misc/trim.cpp"
#include "./src/CTerm.cpp"
#include "./src/CTermTree.cpp"
// #include "./src/CPriority.cpp"
// #include "./src/CPriorityHeap.cpp"
// #include "./src/CDatabase.cpp"

using namespace std;

struct termRecord
{
  string    termKey;
  float     termPriority;
};

int main(int argc, char const *argv[]) {
/*

Key inserted: miroslav masat
miroslav masat,
Key inserted: adela blazkova
adela blazkova,miroslav masat,
Key inserted: michal majer
adela blazkova,michal majer,miroslav masat,
Key inserted: honza dudr
adela blazkova,honza dudr,michal majer,miroslav masat,
Key deleted: miroslav masat
adela blazkova,honza dudr,michal majer,
Key inserted: michal artazov
adela blazkova,honza dudr,michal artazov,michal majer,
Key deleted: michal majer
adela blazkova,honza dudr,michal artazov,
Key inserted: michal durovec
michal artazov,michal durovec,michal majer,honza dudr,michal artazov,
*/
  //CTerm *DTree = new CTerm("mariana gedrova");
  // CTermTree<string> ATree;
  //   ATree.insert("adela blazkova");
  //   //ATree.renderInOrder();
  //   ATree.printInOrder();
  //   ATree.insert("honza dudr");
  //   //ATree.renderInOrder();
  //   ATree.printInOrder();
  //   ATree.insert("michal artazov");
  //   //ATree.renderInOrder();
  //   ATree.printInOrder();
  //   ATree.insert("michal durovec");
  //   //ATree.renderInOrder();
  //   ATree.printInOrder();



  CTermTree<string> DTree;
    DTree.insert("miroslav masat");
    //DTree.renderInOrder();
    DTree.printInOrder();
    DTree.insert("adela blazkova");
    //DTree.renderInOrder();
    DTree.printInOrder();
    DTree.insert("michal majer");
    //DTree.renderInOrder();
    DTree.printInOrder();
    DTree.insert("honza dudr");
    //DTree.renderInOrder();
    DTree.printInOrder();
    DTree.deleteKey("miroslav masat");
    //DTree.renderInOrder();
    DTree.printInOrder();
    DTree.insert("michal artazov");
    ///DTree.renderInOrder();
    DTree.printInOrder();
    DTree.deleteKey("michal majer");
    //DTree.renderInOrder();
    DTree.printInOrder();
    DTree.insert("michal durovec");
    //DTree.renderInOrder();
    DTree.printInOrder();
    //DB.display();

  return 0;
}
