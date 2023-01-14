//  By AestheticAkhmad
//  Created by Akhmad on 14/01/2023.

#ifndef Book_hpp
#define Book_hpp

#include <string>
#include <iostream>

class Book {
private:
    std::string title{};
    std::string author{};
    int price{};
    const uint32_t ISBN;
    int quantity{};
    bool available{true};
public:
    Book(std::string title, std::string author, int price, uint32_t ISBN, int quantity) :
        title(move(title)), author(move(author)), price(price), ISBN(ISBN), quantity(quantity) {}
    
    std::string GetTitle() const;
    std::string GetAuthor() const;
    uint32_t GetISBN() const;
    int GetPrice() const;
    int GetQuantity() const;
    void GetInfo() const;
    
    bool IsAvailable() const;
    void SetQuantity(int change);
};

#endif /* Book_hpp */
