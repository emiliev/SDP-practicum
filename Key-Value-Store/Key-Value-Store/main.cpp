//
//  main.cpp
//  Key-Value-Store
//
//  Created by Emil Iliev on 12/28/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "List.hpp"
#include "HashTable.hpp"
#include "Pair.hpp"
#include "FileManager.hpp"
using namespace std;

const int kKeyLength = 256;


/////////TODO/////////
/*

 UNIQUE KEYS
 REWORED SEARCH FUNCTION IN LINKED LIST
 
 ETC..
*/

int main(int argc, const char * argv[]) {
    
    HashTable<char*, int> phonebook(1000);
    char word[kKeyLength];

    std::clock_t begin_time = clock();
    cin.getline(word, kKeyLength);
    Pair<char*, int> temp;
    temp.key = word;
    
    phonebook.Store(word, 16789);
    phonebook.Erase(word);
    if(phonebook.Load(temp)){
    
        cout<<"found it for: "<<(clock() - begin_time) / CLOCKS_PER_SEC<<endl;
        cout<<temp.key<<" for value: "<<temp.value<<endl;
    }
    else{
        cout<<"found nothing \n";
    }

    return 0;
}
