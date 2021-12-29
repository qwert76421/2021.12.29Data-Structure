// CPP program to implement hashing with chaining
//#include<bits/stdc++.h>
#include "Hash.h"

Hash::Hash(long long M)
{
    this->BUCKET = M;
    table = new list<int>[BUCKET];
    r1 = rand()%M;
    r2 = rand()%M;
    r3 = rand()%M;
    r4 = rand()%M;
}

unsigned long long Hash::transform(int value){
    int  n = value;
    unsigned long long sum = 0;
    sum += ( r1 * (n % 256));
    n /= 256;
    sum += ( r2 * (n % 256));
    n /= 256;
    sum += ( r3 * (n % 256));
    n /= 256;
    sum += ( r4 * (n % 256));
    return sum;
}

//2 bytes
/*unsigned long long Hash::transform(int value){
    int  n = value;
    unsigned long long sum = 0;
    sum += ( r1 * (n % 65536));
    n /= 65536;
    sum += ( r2 * (n % 65536));

    return sum;
}*/

void Hash::insertItem(int value){
    int index = hashFunction(value);
    table[index].push_back(value);
}
 
void Hash::deleteItem(int key){
  // get the hash index of key
  int index = hashFunction(key);
 
  // find the key in (index)th list
  list <int> :: iterator i;
  for (i = table[index].begin();
           i != table[index].end(); i++) {
    if (*i == key)
      break;
  }
 
  // if key is found in hash table, remove it
  if (i != table[index].end())
    table[index].erase(i);
}
 
void Hash::SearchItem(int value){
  // get the hash index of key
  int index = hashFunction(value);
 
  // find the key in (index)th list
  list <int> :: iterator i;
  for (i = table[index].begin();
           i != table[index].end(); i++) {
    if (*i == value)
      break;
  }
}

// function to display hash table
void Hash::displayHash() {
  for (int i = 0; i < BUCKET; i++) {
    cout << i;
    for (auto x : table[i])
      cout << " --> " << x;
    cout << endl;
  }
}
 
// Driver program
/*int main()
{
  // array that contains keys to be mapped
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a)/sizeof(a[0]);
 
  // insert the keys into the hash table
  Hash h(7);   // 7 is count of buckets in
               // hash table
  for (int i = 0; i < n; i++)
    h.insertItem(a[i]); 
 
  // delete 12 from hash table
  h.deleteItem(12);
 
  // display the Hash table
  h.displayHash();
 
  return 0;
}*/

