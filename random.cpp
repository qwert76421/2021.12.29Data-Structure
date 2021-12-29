#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ofstream file;
    file.open("source1.txt", ios_base::app);
    int a = pow(2,30);
    long long *insert_arr = new long long[a]{0};
    long long *search_arr = new long long[100000]{0};

    for(long long i=0;i<a;i++){
        insert_arr[i] = (rand()%a)+1;
        file << insert_arr[i] <<" " ;
    }
    delete [] insert_arr;

    //Search_arr
    for(long long i=0;i<100000;i++){
        search_arr[i] = (rand()%a)+1;
        file << search_arr[i] << " " ;
    }
    delete [] search_arr;
    file.close();
}
