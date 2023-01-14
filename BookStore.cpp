//
//  BookStore.cpp
//  BookStore
//
//  Created by Akhmad Oripov  on 14/01/2023.
//

#include "BookStore.hpp"

BookStore::BookStore() {
    BookDataCollector bookDataCollector(books, booksByTitle, booksByISBN);
}

void BookStore::ListAll() const {
    std::cout<<"Number of titles available: "<<books.size()<<"\n";
    for(auto i : books) {
        std::cout<<i->GetTitle()<<"\t\tPrice: "<<i->GetPrice()<<"\n";
    }
}
