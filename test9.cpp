#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
 
#include "myvector.h"
// #include "catch.hpp"
 
using namespace std;
 
 
int main()
    
{
  myvector<int>  V1;
  myvector<double> V2;
  myvector<char> V3;
 
  cout << (V1.size() == 0);
  cout << (V2.size() == 0);
  cout << (V3.size() == 0);
 
  V1.push_back(123);
 
   cout << (V1.size() == 1);
   cout << (V2.size() == 0);
   cout << (V3.size() == 0);
 
   V2.push_back(3.14);
   V2.push_back(999.0);
 
   cout << (V1.size() == 1);
   cout << (V2.size() == 2);
   cout << (V3.size() == 0);
   cout << (V1.at(0) == 123);
   
   V3.push_back('a');
   V3.push_back('-');
   V3.push_back('z');
 
   cout << (V1.size() == 1);
   cout << (V2.size() == 2);
   cout << (V3.size() == 3);
   cout << (V1.at(0) == 123);
   cout << (V3.at(2) == 'z');
   cout << (V3.at(1) == '-');
   cout << (V3.at(0) == 'a');
}
