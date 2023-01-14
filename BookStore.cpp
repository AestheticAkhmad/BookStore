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

void BookStore::FindBook(std::string &title) const {
    title.erase(std::remove_if(
        begin(title), end(title),
        [l = std::locale{}](auto ch) {
            if(ispunct(ch) != 0) return ispunct(ch, l);
            if(isspace(ch) != 0) return isspace(ch, l);
            return std::ispunct(ch, l);
        }
    ), end(title));
    
    std::transform(title.cbegin(), title.cend(), title.begin(),
                   [](unsigned char c) {return std::toupper(c);});
    
    auto findBook = booksByTitle.find(title);
    if(findBook != booksByTitle.end()) {
        std::cout<<findBook->second->GetTitle()<<" has been found.\n";
    } else {
        std::cout<<"The book hasn't been found.\n";
    }
}
