// Prof. Joe Hummel
// U. of Illinois, Chicago
// CS 251, Fall 2019
// Project #01: myvector
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

#include "myvector.h"
// #include "catch.hpp"

using namespace std;


int main()
{
    myvector<int>  V;
    
    int N = 120;
    
    for (int i = 0; i < N; i++)
        V.push_back(i+1);
    
    cout << (V.size() == N);
    
     //delete every other element:
    for (int i = N-1; i >= 0; i = i - 2)
    {
        int x = V.erase(i);
        cout << (x == (i + 1));
    }

//    int x = V.erase(119);
//    cout << (x == (119 + 1));
    
    

    // make sure remaining elements are correct:
    cout << (V.size() == (N/2));

    for (int i = 0; i < N / 2; i++)
        cout << (V[i] == (2*i + 1));
}
