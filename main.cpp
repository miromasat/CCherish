#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include "./misc/trim.cpp"
#include "./src/CTerm.cpp"
#include "./src/CTermTree.cpp"
#include "./src/CPriority.cpp"
#include "./src/CPriorityHeap.cpp"
#include "./src/CDatabase.cpp"

using namespace std;

template <class T>
class termRecord
{
  public:
    termRecord(T TK, float TP) : termKey(TK), termPriority(TP) {}
    T getTerm()     {return termKey;}
    float getPriority() {return termPriority;}

  private:
      T    termKey;
      float     termPriority;
};

int main(int argc, char const *argv[]) {

  string  k, p;
  string s;

  ifstream myfile (argv[1]);

  //CTerm *DTree = new CTerm("mariana gedrova");

  int y = 25000;
  CDatabase<int> DB(y);
  vector<termRecord<int> > input;

  while (getline(cin, s))
    {
      char a;
      if (--y < 0) break;

      string delimiter = ",";
      k = s.substr(0, s.find(delimiter));
      s.erase(0, s.find(delimiter) + delimiter.length());
      p = s.substr(0, s.find(delimiter));

      string::size_type sz;   // alias of size_t
      int k1 = std::stoi (k,&sz);
      int p1 = std::stoi (p,&sz);

      input.push_back(termRecord<int>(k1, p1));

    }

  clock_t begin = clock();
    for (unsigned i = 0; i < input.size(); i++) {
      DB.insert(input[i].getTerm(), input[i].getPriority());
    }

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << "Time: " << elapsed_secs << std::endl;

  myfile.close();


  return 0;
}
