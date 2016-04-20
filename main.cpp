#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "./misc/trim.cpp"
#include "./src/CTerm.cpp"


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

  CTerm *DTree = new CTerm();

  while ( getline(myfile,k,',') )
    {     getline (myfile,p);
          trim(k); trim(p);
          transform(k.begin(), k.end(), k.begin(), ::tolower);

      entry->termKey      = k;
      entry->termPriority = ::atof(p.c_str());

      DTree->insert(DTree, entry->termKey);

      cout << entry->termKey << " with a priority of " << entry->termPriority << endl;
    }


  myfile.close();


  return 0;
}
