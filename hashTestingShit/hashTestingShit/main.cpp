//
//  main.cpp
//  hashTestingShit
//
//  Created by Emil Iliev on 1/23/16.
//  Copyright © 2016 Emil Iliev. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;


char* newHash(char* buffer){
    
    size_t len = strlen(buffer);
    cout<<len<<endl;
    
    char* key = new char[33];
    key[32] = '\0';
    char buf[] = "abcdefghijkl%!@pqrstuvwxyz~(){}#";

    for(int index = 0; index < 32; ++index){
        
        key[index] = buffer[index % len] ^ buf[index];
    }
    
    cout<<key<<endl;
    return key;
}

int main(int argc, const char * argv[]) {
   

    int value;
    cin>>value;
    char buffer[32];

    sprintf(buffer, "%d", value);
    char* p = newHash(buffer);
    
    return 0;
}
