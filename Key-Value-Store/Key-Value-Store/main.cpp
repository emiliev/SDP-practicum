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
using namespace std;

//void Store(char* info, size_t size){
//    
//   
//    long index = stringHash(info, size);
//    char place[32];
//    sprintf(place, "%ld", index);
//    cout<<place<<endl;
//    
//    char key[11] = "ABCDEFGHIJ";
//    
//    
//    
//    
//   // decrypt(&place);
//    int counter  = 0;
//    for(int index = 0; index < strlen(place); ++index){
//        
//        place[index] = place[index]^key[counter++];
//        
//        if (counter % 11 == 0) {
//            counter = 0;
//        }
//    }
//    
//    counter = 0;
//    for(int index = 0; index < strlen(place); ++index){
//        
//        place[index] = place[index]^key[counter++];
//        
//        if (counter % 11 == 0) {
//            counter = 0;
//        }
//    }
//    char* pend;
//    long numb;
//    numb = strtol(place, &pend, 10);
//    cout<<numb<<" bytnat v long\n";
//}

int main(int argc, const char * argv[]) {
    
    char a[] = "gosho";
    
    char names[][15] = {"gosho", "tosho", "pesho", "stoqn", "ceko", "mariqn", "emil", "geri", "nikol", "brat my ","kolyo"};
    HashTable<char*, int> phonebook(1000);
    
    for(int i = 0; i < 11; ++i){
        for(int index = 0; index < 20; ++index){
    
            phonebook.Store(names[i], index);
        }
    }
    
    Pair<char*, int> *temp = phonebook.Load(names[0]);
    cout<<"key : "<<temp->key<<" for value: "<<temp->value<<endl;
    phonebook.Erase(a);

    Pair<char*, int> *temp1 = phonebook.Load(a);
    if(temp1){
        
        cout<<"key : "<<temp1->key<<" for value: "<<temp1->value<<endl;
    }

    
//    
//    ofstream myfile;
//    myfile.open ("example.txt", ios::app);
//    myfile << "Writing this to a file123.\n";
//    myfile.close();
//    
//    char asd[100];
//    ifstream i;
//    i.open("example.txt");
//    if(i){
//        
//        i.getline(asd, 100);
//        cout<<asd;
//    }
//
//    
//    i.close();


    return 0;
}
