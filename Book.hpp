//
//  Book.hpp
//  BookStore
//
//  Created by Akhmad Oripov  on 14/01/2023.
//

#ifndef Book_hpp
#define Book_hpp

#include <string>

class Book {
private:
    std::string title{};
    int price{};
    const uint64_t ISBN;
public:
    Book(std::string title, int price, uint64_t ISBN) :
        title(move(title)), price(price), ISBN(ISBN) {}
    
};

#endif /* Book_hpp */
