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
        std::cout<<"Title: "<<i->GetTitle()<<"\t| By "<<i->GetAuthor()<<"\n";
        std::cout<<"Price: $"<<i->GetPrice()<<"\t| ISBN: "<<i->GetISBN()<<"\n";
        std::cout<<"-----------------------\n";
    }
}
