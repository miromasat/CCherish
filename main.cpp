#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
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
// options to run the main are
// -v (verbose) will print contents of the database or operation after every run of it
// -t (test) will run series of insertions and searches for every key in the database, while using this mode, please send in some of test files using standard input (< data/sample01.txt)
// -string (-int) will prepare the database for working with strings (integers) as keys in the database
// -cap (capacity) does set up the maximal capacity of the database system, default capacity is 25000
// minimal mode of run is with -string (-int) only, which introduces the INTERACTIVE MODE
// INTERACTIVE mode supports these operations:
//      - inserting a key with a given priority e.g. "insert:Miroslav Masat:99"
//      - searching a key e.g. "search:Miroslav Masat"
//      - displaying the content of the database e.g. display

int main(int argc, char const *argv[]) {
  bool verbose, test, isString, isInt;
  int capacity = 25000;
  verbose = test = isString = isInt = false;

  if (argc > 1)
    cout << "The executable options are : ";

  for (int i = 1; i < argc; i++)
  {
    if (strncmp (argv[i],"-v",2) == 0) { verbose = true; cout << "verbose=true, "; }
    if (strncmp (argv[i],"-t",2) == 0)
    {
      test = true;
      cout << "testmode=true, ";
    }
    if (strncmp (argv[i],"-string",3) == 0) { isString = true; cout << "datatype=string, "; }
    if (strncmp (argv[i],"-int",3) == 0) { isInt = true; cout << "datatype=integer, ";}
    if (strncmp (argv[i],"-cap",3) == 0)
    {
      string paste( argv[i] );

      size_t pos = paste.find("-cap=");
      paste = paste.substr (pos+5);

      string::size_type sz;
      capacity = std::stoi (paste,&sz);
      cout << "maximalCapacity=" << capacity << ", ";
    }
  }
  if (!verbose) cout << "verbose=false, ";
  if (!test) cout << "interactive=true, ";
  cout << endl;

  string  k, p;
  string s;

    CDatabase<string> DB_string(capacity);
    vector<termRecord<string> > input_string;

    CDatabase<int> DB_int(capacity);
    vector<termRecord<int> > input_int;


if (test)
  {

  while (getline(cin, s))
    {
      char a;
      if (--capacity < 0) break;

      string delimiter = ",";
      k = s.substr(0, s.find(delimiter));
      s.erase(0, s.find(delimiter) + delimiter.length());
      p = s.substr(0, s.find(delimiter));

      string::size_type sz;
      int p1 = std::stoi (p,&sz);

      if (isString) {
        DB_string.insert(k, p1);
        input_string.push_back(termRecord<string>(k, p1));
        if (verbose)
          DB_string.display();

      }else{
        int k1 = std::stoi (k,&sz);
        DB_int.insert(k1, p1);
        input_int.push_back(termRecord<int>(k1, p1));
        if (verbose)
          DB_int.display();
      }

    }

    clock_t begin = clock();
      int final = (isString) ? input_string.size(): input_int.size();
      for (unsigned i = 0; i < final; i++) {
        if (isString) {
          string f = DB_string.search(input_string[i].getTerm());
          if (verbose)
          {
            cout << ">>>>>>>>>>>>>SEARCH" << endl;
            cout << "key: " << input_string[i].getTerm() << endl;
            if (f == "") cout << "NOT ";
              cout << "FOUND ";
            cout << "SEARCH>>>>>>>>>>>>>" << endl;
          }
        }else{
          int f = DB_int.search(input_int[i].getTerm());
          if (verbose)
          {
            cout << ">>>>>>>>>>>>>SEARCH" << endl;
            cout << "key: " << input_int[i].getTerm() << endl;
            if (f == 0) cout << "NOT ";
              cout << "FOUND ";
            cout << "SEARCH>>>>>>>>>>>>>" << endl;
          }
        }

      }
      clock_t end = clock();
      double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
      std::cout << "Time: " << elapsed_secs << std::endl;
  }else{
    while (getline(cin, s))
      {
        string OP, keyS;
        int keyI;
        float P;
        string delimiter = ":";
        OP = s.substr(0, s.find(delimiter));

        if (isString) { //INTERACTIVE MODE FOR STRINGS
          OP = s.substr(0, s.find(delimiter));
          if (OP == "insert"){
              s.erase(0, s.find(delimiter) + delimiter.length());
            keyS = s.substr(0, s.find(delimiter));
              s.erase(0, s.find(delimiter) + delimiter.length());
              string::size_type sz;
            P = std::stoi ( s.substr(0, s.find(delimiter)), &sz );

            DB_string.insert(keyS, P);
            if (verbose)
              DB_string.display();

          }else if (OP == "search"){
              s.erase(0, s.find(delimiter) + delimiter.length());
            keyS = s.substr(0, s.find(delimiter));
            string f = DB_string.search(keyS);
            if (verbose)
            {
              cout << ">>>>>>>>>>>>>SEARCH" << endl;
              cout << "key: " << keyS << endl;
              if (f == "") cout << "NOT ";
                cout << "FOUND ";
              cout << "SEARCH>>>>>>>>>>>>>" << endl;
            }
          }else if (OP == "display"){
            DB_string.display();
          }else{
            cout << "Unknown operator, supported are insert:key:priority, search:priority or display, try again." << endl;
          }
        }else{ //INTERACTIVE MODE FOR INTEGERS
          OP = s.substr(0, s.find(delimiter));
          if (OP == "insert"){
              string::size_type sz;
              s.erase(0, s.find(delimiter) + delimiter.length());
            keyI = std::stoi ( s.substr(0, s.find(delimiter)) );
              s.erase(0, s.find(delimiter) + delimiter.length());
            P = std::stoi ( s.substr(0, s.find(delimiter)), &sz );

            DB_int.insert(keyI, P);
            if (verbose)
              DB_int.display();

          }else if (OP == "search"){
              string::size_type sz;
              s.erase(0, s.find(delimiter) + delimiter.length());
            keyI = std::stoi ( s.substr(0, s.find(delimiter)) );
            int f = DB_int.search(keyI);
            if (verbose)
            {
              cout << ">>>>>>>>>>>>>SEARCH" << endl;
              cout << "key: " << keyI << endl;
              if (f == 0) cout << " NOT";
                cout << " FOUND ";
              cout << "SEARCH>>>>>>>>>>>>>" << endl;
            }
          }else if (OP == "display"){
            DB_int.display();
          }else{
            cout << "Unknown operator, supported are insert:key:priority, search:priority or display, try again." << endl;
          }
        }

      }
  }

  return 0;
}
