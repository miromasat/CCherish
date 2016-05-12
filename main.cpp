#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
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
  int y = 5000;
  CDatabase<string> DB(y);

  clock_t begin = clock();
  while ( getline(myfile,k,',') && y>0 )
    {     getline (myfile,p);
          trim(k); trim(p);
          transform(k.begin(), k.end(), k.begin(), ::tolower);
      y--;
      entry->termKey      = k;
      entry->termPriority = ::atof(p.c_str());

      DB.insert(entry->termKey, entry->termPriority);
      //DB.display();
    }
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << "Time: " << elapsed_secs << std::endl;

  myfile.close();


  return 0;
}
