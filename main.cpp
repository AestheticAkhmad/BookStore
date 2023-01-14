//
//  main.cpp
//  BookStore
//
//  Created by Akhmad Oripov  on 14/01/2023.
//

#include <iostream>
#include "BookStore.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    BookStore bookStore;
    bookStore.ListAll();
    
    string bookToFind{};
    cout<<"What book do you want to find?: ";
    getline(cin, bookToFind);
    bookStore.FindBook(bookToFind);
    
    return 0;
}
