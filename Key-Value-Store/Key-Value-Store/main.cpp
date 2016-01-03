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

template <typename T>
void test(){
    
    
    char names[][10] = {"ala", "bala", "porto", "kalaaa", "kashvala", "salamaa", "guz"};
    ofstream i1("example1.dat", ios::binary);
    for(int index = 0; index < 7; ++index){
        
        int length = strlen(names[index]);
        i1.write((char*)&length, sizeof(length));
        i1.write(names[index], strlen(names[index]));
    }
    i1.close();
    
    ifstream input("example1.dat", ios::binary);
    if(input){
        
        while (!input.eof()) {
            
            int wordLength = 0;
            input.read((char*)&wordLength, sizeof(wordLength));
            if(!input){
                cout<<"krai na inputa \n";
                break;
            }
            char* word = new char[wordLength];
            input.read(word,wordLength);
            
            if(strcmp(word, "guz") == 0){
                streampos p;
                p = input.tellg();
                int remaining = wordLength + sizeof(wordLength);
                p -= remaining;
                
                ofstream newRecord("example1.dat", ios::binary | ios::in);
                newRecord.seekp(p);
                if(newRecord){
                    
                    while (!input.eof()) {
                        
                        int newWordLength = 0;
                        input.read((char*)&newWordLength, sizeof(newWordLength));
                        if(!input){
                            cout<<"krai na newRecord!\n";
                            break;
                        }
                        char* newWord = new char[newWordLength];
                        input.read(newWord, newWordLength);
                        newRecord.write((char*)&newWordLength, sizeof(newWordLength));
                        newRecord.write(newWord, newWordLength);
                        
                        cout<<newWordLength<<" "<<newWord<<endl;
                        delete newWord;
                    }
                    
                    while (remaining != 0) {
                        
                        newRecord<<'\0';
                        remaining--;
                    }
                }
                
                newRecord.close();
            }
            cout<<wordLength<<" "<<word<<endl;
            delete word;
        }
    }

    input.close();
    
    
//    ifstream testReader("example1.dat", ios::binary);
//    if(testReader){
//        
//        while (!testReader.eof()) {
//            
//            int num = 0;
//            testReader.read((char*)&num, sizeof(num));
//            if(!testReader){
//                
//                cout<<"Krai na cheteneto!\n";
//                break;
//            }
//            
//            char* bufferNum = new char[num];
//            testReader.read(bufferNum, num);
//            cout<<num<<" "<<bufferNum<<endl;
//            
//            delete bufferNum;
//        }
//    }
}

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

    
//    test<char*>();
    return 0;
}
