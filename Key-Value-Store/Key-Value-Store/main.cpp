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

bool Load(char* pKey, char*& info,size_t& size){

    return true;
}

bool Erase(char* pKey){
    
    return true;
}




int main(int argc, const char * argv[]) {
    
    char test[] = "tovaeshegda";
    char a[] = "gosho";
    HashTable<char*, int> phonebook(1000);
    phonebook.Store(a, 15);
    
//cout<<temp.key<<"for value: "<<temp.value<<endl;
//    ofstream myfile;
//    myfile.open ("example.txt");
//    myfile << "Writing this to a file.\n";
//    myfile.close();
//    
//    char asd[100];
//    ifstream i;
//    i.open("example.txt");
//    if(i){
//    
////        i>>asd;
//  //      i.read(asd, 100);
//    }
//
//    i.close();
//       remove("example.txt");
//    cout<<asd;
//    return 0;
}
