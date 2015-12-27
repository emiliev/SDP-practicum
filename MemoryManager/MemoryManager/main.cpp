//
//  main.cpp
//  MemoryManager
//
//  Created by Emil Iliev on 12/26/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include <iostream>
#include "cstring"

using namespace std;

int main(){

    char buffer[15];
//    int *number1 = (int*)(&buffer);
//    *number1 = 123456789;
    int number = 123456789;
    memcpy(buffer, &number, sizeof(number));
    cout<<buffer<<endl;
    
    char buffer2[5];
    int* number1 = (int*)(&buffer2);
    *number1 = 123456789;
    
    
    //posledniq bit na chisloto
    int result = *number1 & 1;
    cout<<result;
    cout<<endl<<(int*)&buffer2<<endl;
    
    
    //invertirane na purviq bit
    int b  = 19;
    int result1 = (b ^ 1) & 1;
    cout<<result1<<endl;
   
//    
//    
//    cout<<endl<<strlen(buffer)<<" "<<buffer<<endl;
//    
//    char buffer1[5];
//    int number = 123456789;
//    sprintf(buffer1, "%d", number);
//    
//    cout<<strlen(buffer1)<<" "<<buffer1<<endl;
    
    
}