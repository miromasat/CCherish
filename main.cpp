#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "./misc/trim.cpp"
#include "./src/CTerm.cpp"
#include "./src/CTermTree.cpp"
#include "./src/CPriority.cpp"
#include "./src/CPriorityHeap.cpp"
#include "./src/CDatabase.cpp"

using namespace std;

struct termRecord
{
  string    termKey;
  float     termPriority;
};

termRecord*  parseRecord(termRecord* rec, string entry)
{
  transform(entry.begin(), entry.end(), entry.begin(), ::tolower);
  trim(entry);

  return rec;
}

int main(int argc, char const *argv[]) {

  string  k, p;
  termRecord *entry = new termRecord;
  ifstream myfile (argv[1]);

  //CTerm *DTree = new CTerm("mariana gedrova");
  CTermTree<string> DTree;
  CPriorityHeap<string> PTree;
  CDatabase<string> DB(3);

  //DTree->remove(DTree, "root");
  while ( getline(myfile,k,',') )
    {     getline (myfile,p);
          trim(k); trim(p);
          transform(k.begin(), k.end(), k.begin(), ::tolower);

      entry->termKey      = k;
      entry->termPriority = ::atof(p.c_str());

      DTree.insert(entry->termKey);
      DB.insert(entry->termKey, entry->termPriority);
      //DB.display();
    }

    DB.deleteKey("michal artazov");
    DB.display();
    DB.deleteKey("filip trefil");
    DB.display();


    DB.search("kaja pikorova");
    DB.search("radek cehak");
    DB.search("miroslav hrncir");
    DB.display();


  myfile.close();


  return 0;
}
