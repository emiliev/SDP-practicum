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

template <typename T>
void test(){
    
    
    char names[][10] = {"ala", "bala"};
    ofstream i1("example1.dat", ios::binary);
    for(int index = 0; index < 2; ++index){
        
        int length = strlen(names[index]);;
        i1.write((char*)&length, sizeof(length));
        i1.write(names[index], strlen(names[index]));
    }
    i1.close();
    
    T type;
    ifstream i("example1.dat", ios::binary);
    if(i){
        
        while (!i.eof()) {
            
            int digit;
            i.read((char*)&digit, sizeof(digit));
            char *buffer = new char[digit];
            i.read(buffer,digit);
            type = reinterpret_cast<T>(buffer);
            cout<<type<<endl;
            
            delete [] buffer;
        }
    }
    i.close();
}
int main(int argc, const char * argv[]) {
    
    HashTable<char*, int> phonebook(1000);
    int generator = 0;
    char names[][10] = {"geri", "nikol", "gosho", "pesho", "bogdan", "emil", "miroslav", "slavcho", "petran"};
    char word[32] ;

    std::clock_t begin_time = clock();
    for (int index = 0; index < 10; ++index){
        ifstream input("example.txt");
    
        if(input){
        
            while (!input.eof()) {
            
                input>>word;
                strcat(word,names[index]);
                phonebook.Store(word, generator++);

            }
        }
            input.close();
    }
    Pair<char*, int> *temp = phonebook.Load(word);

    if(temp){
        
        cout<<"found it for: "<<(clock() - begin_time) / CLOCKS_PER_SEC<<endl;
        cout<<temp->key<<" for value: "<<temp->value<<endl;
    }
    
//    test<char*>();
    return 0;
}
