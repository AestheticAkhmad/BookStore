//  GitHub profile: https://github.com/AestheticAkhmad
//  By AestheticAkhmad
//  Created by Akhmad on 14/01/2023.

#include <iostream>
#include "BookStore.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    BookStore bookStore;
    bookStore.ListAll();
    
    while(true) {
        char choice{};
        cout<<"How do you want to find book to buy?\n";
        cout<<"By ISBN write i or Title write t: ";
        cin>>choice;
        if(choice == 't') {
            string bookToFind{};
            cout<<"Enter title: ";
            cin.ignore();
            getline(cin, bookToFind);
            bookStore.BuyBook(bookToFind, 0);
        } else if(choice == 'i') {
            cout<<"Enter ISBN: ";
            uint32_t ISBN;
            cin>>ISBN;
            string emptyTitle = "-----";
            bookStore.BuyBook(emptyTitle, ISBN);
        } else {
            break;
        }
        cout<<"Do you wish to continue shopping?(yes/no): ";
        cin>>choice;
        if(choice == 'y') {
            continue;
        } else {
            break;
        }
    }
    return 0;
}
