//
//  Book.cpp
//  BookStore
//
//  Created by Akhmad Oripov  on 14/01/2023.
//

#include "Book.hpp"

std::string Book::GetTitle() const {
    return title;
}

std::string Book::GetAuthor() const {
    return author;
}

uint32_t Book::GetISBN() const {
    return ISBN;
}

int Book::GetPrice() const {
    return price;
}
