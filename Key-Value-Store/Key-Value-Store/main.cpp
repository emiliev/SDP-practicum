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
#include "IOManager.hpp"
using namespace std;

/////////TODO/////////
/*


 Caching mechanism
 
 ETC..
*/

int main(int argc, const char * argv[]) {
    
    HashTable<size_t,char*> table(1000);
    char value[1000];
    std::cin.getline(value, 1000);
    size_t key = table.Store(value);
//    size_t key = 7095897;
    cout<<key<<endl;
    Pair<size_t,char*> temp;
    temp.key = key;
    if(table.Load(temp)){
       
        cout<<temp.key<<" "<<temp.value<<endl;
        temp.value = NULL;
    }
    
//    table.Erase(key);
    //if(table.Load(temp)){
//        
//        cout<<temp.key<<" "<<temp.value<<endl;
//        delete [] temp.value;
//        temp.value = NULL;
//    }
//    
//    size_t b = table.Store(a);
//    Pair<size_t, char*> temp1;
//    temp.key = b;
//    if(table.Load(temp1)){
//        
//        cout<<temp1.key<<" "<<temp1.value<<endl;
//        delete [] temp1.value;
//        temp1.value = NULL;
//    }
    return 0;
}
