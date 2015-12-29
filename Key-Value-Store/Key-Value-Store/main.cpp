//
//  main.cpp
//  Key-Value-Store
//
//  Created by Emil Iliev on 12/28/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "List.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    
    LinkedList<int> *listche = new LinkedList<int>[10];

    delete []listche;
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
