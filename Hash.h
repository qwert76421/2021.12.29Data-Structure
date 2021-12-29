#ifndef _HASH_H_
#define _HASH_H_

#include <iostream>
#include <list>

using namespace std;
 
class Hash{
private:
    long long  BUCKET;    // No. of buckets
 
    // Pointer to an array containing buckets
    list<int> *table;
    int r1,r2,r3,r4;

public:
    Hash(long long M);  // Constructor

    unsigned long long transform(int value);
 
    // inserts a value into hash table
    void insertItem(int value);
 
    // deletes a value from hash table
    void deleteItem(int value);

    // hash function to map values to key
    int hashFunction(int x) {
        unsigned long long num = transform(x);
        return (num % BUCKET);
    }
 
    void displayHash();

    // search a value from hash table
    void SearchItem(int value);
};


#endif
