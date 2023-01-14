//  By AestheticAkhmad
//  Created by Akhmad on 14/01/2023.

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

bool Book::IsAvailable() const {
    return available;
}

int Book::GetQuantity() const {
    return quantity;
}

void Book::GetInfo() const {
    std::cout<<"--------------------------------------\n";
    std::cout<<"Title: "<<title<<"\n";
    std::cout<<"Author: "<<author<<"\t| ISBN: "<<ISBN<<"\n";
    std::cout<<"Price: "<<price<<"\n";
    std::cout<<"--------------------------------------\n";
}

void Book::SetQuantity(int change) {
    quantity += change;
    if(quantity <= 0) {
        available = false;
    } else {
        available = true;
    }
}
