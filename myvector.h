/*myvector.h*/

//
// <Arvinbayar Jamsranjav>
// U. of Illinois, Chicago
// CS 251: Fall 2019
//
// Project #01: myvector class that mimics std::vector, but with my own
// implemenation outlined as follows:
//
// ???
//

#pragma once

#include <iostream>  // print debugging
#include <cstdlib>   // malloc, free

using namespace std;

template<typename T>
class myvector
{
private:
    struct NODE
    {
        T  Data;
        struct NODE* Next;
    };
    struct NODE* Head;
    struct NODE* Tail;
    int Size;
    
    // Used for at() function ...
    struct NODE* lastNode;
    int lastIndex;
    
public:
    // Default constructor
    //
    myvector()
    {
        Head = NULL;
        Tail = NULL;
        Size = 0;
        lastNode = NULL;
        lastIndex = -1;
    }
    
    // Constructor with initial size
    //
    myvector(int initial_size)
    {
        Head = NULL;
        Tail = NULL;
        Size = 0;
        
        // Initializing my linked list to empty T{} using push_back
        // function that exists below ...
        //
        for(int j = 0; j < initial_size; j++) {
            push_back(T{});
        }
    }
    
    // Copy constructor for parameter passing
    //
    myvector(const myvector& other)
    {
        NODE* temp = new struct NODE();
        temp = other.Head;
        this->Head = NULL;
        this->Tail = NULL;
        Size = other.Size;
        
        // Creating copy constructor using push_back function
        // that exists below, changing the Size ...
        //
        for(int i = 0; i < other.Size; i++){
            push_back(temp->Data);
            temp = temp->Next;
        }
        this->Size = other.Size;
    }
    
    // Function that returns to the Size ...
    //
    int size()
    {
        return Size;
    }
    
    // Function that return to the value
    // that exists on i-th index ...
    //
    T& at(int i)
    {
        // Improvement to my linked list
        // More efficient way to access when trying
        // to access first and last element on
        // i-th position ...
        //
        if (i == 0) {
            lastNode = Head;
            lastIndex = 0;
            return Head->Data;
        }
        else if (i == lastIndex + 1) {
            lastNode = lastNode->Next;
            lastIndex++;
            return lastNode->Data;
        }
        // Non-consecutive
        // Traverses down LL
        //
        else {
            NODE* pTemp = Head;
            for (int j = 0; j < i; j++) {
                pTemp = pTemp->Next;
                lastIndex++;
            }
            return pTemp->Data;
        }
    }
    
    // Inserting elements to the back of my LL
    // and adding Size by one ...
    //
    void push_back(T value)
    {
        struct NODE* newNode = new struct NODE();
        newNode->Data = value;
        newNode->Next = NULL;
        
        if (Head == NULL) {
            Head = newNode;
        }
        else {
            Tail->Next = newNode;
        }
        Tail = newNode;
        Size++;
    }
    
    // Erase function that removes element on i-th
    // position, updates the LL then returns to the
    // value of i ...
    //
    T erase (int i)
    {
        NODE* sucNode = Head;
        NODE* curNode = NULL;
        T value = at(i);
        // It covered 3 cases of erase:
        // erasing first, mid and last element ...
        //
        for (int j = 0; j < Size; j++) {
            if (j == i) {
                if (curNode == NULL && Head != NULL) {
                    sucNode = Head->Next;
                    Head = sucNode;
                    Size--;

                    if (sucNode == NULL) {
                        Tail = NULL;
                    }
                }
                else if (curNode->Next != NULL) {
                    sucNode = curNode->Next->Next;
                    curNode->Next = sucNode;
                    Size--;

                    if (sucNode == NULL) {
                        Tail = curNode;
                    }
                }
            }
            else {
                curNode = sucNode;
                sucNode = sucNode->Next;
            }
        }
        return value;
    }
    
    // returns to the element at position i
    //
    T& operator[] (int i) {
        return at(i);
    }
    
    // return the elements in the range of i-j,
    // i and j included. use * in order to see actual elements
    // 
    T* rangeof(int i, int j) {
        T* newTemp = new T[j-i+1];
        int counter = 0;
        for (int k = 0; k < Size; k++) {
            if ( k == i) {
                for (int w = 0; w < (j-i+1); w++) {
                    newTemp[counter]= this->at(k+w);
                    counter++;
                }
            }
        }
        return newTemp;
    }
};
