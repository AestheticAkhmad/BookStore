//  By AestheticAkhmad
//  Created by Akhmad on 14/01/2023.

#include "BookStore.hpp"

BookStore::BookStore() {
    BookDataCollector bookDataCollector(books, booksByTitle, booksByISBN);
}

void BookStore::ListAll() const {
    std::cout<<"Number of titles available: "<<books.size()<<"\n";
    for(auto i : books) {
        std::cout<<"Title: "<<i->GetTitle()<<"\t| By "<<i->GetAuthor()<<"\n";
        std::cout<<"Price: $"<<i->GetPrice()<<"\t| ISBN: "<<i->GetISBN()<<"\n";
        std::cout<<"-----------------------------\n";
    }
}

auto BookStore::FindBook(std::string &title, uint32_t ISBN) const {
    if(ISBN <= 100000) {
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
            return findBook->second;
        } else {
            std::cout<<"The book was not found.\n";
        }
        return std::shared_ptr<Book>(nullptr);
    }
    auto findBook = booksByISBN.find(ISBN);
    if(findBook != booksByISBN.end()) {
        return findBook->second;
    } else {
        std::cout<<"The book with the ISBN was not found.\n";
    }
    return std::shared_ptr<Book>(nullptr);
}


void BookStore::BuyBook(std::string &title, uint32_t ISBN) {
    std::shared_ptr<Book> book;
    book = FindBook(title, ISBN);
    
    if(book == nullptr) return;
    
    if(book->IsAvailable() == false) {
        std::cout<<"The book is not available.\n\n";
    } else {
        book->GetInfo();
        while(true) {
            int count{};
            std::cout<<"How many books do you want to buy?: ";
            std::cin>>count;
            if(count <= 0) {
                std::cout<<"Number cannot be less than or equal to zero.\nEnter different value.\n";
                continue;
            } else if(count > book->GetQuantity()) {
                std::cout<<"We do not have that amount of books currently available.\nEnter different value.\n\n";
                continue;
            } else {
                std::string confirm{};
                std::cout<<"Proceed to checkout(yes/no): ";
                std::cin>>confirm;
                if(confirm == "yes") {
                    CheckOut(book, count);
                } else {
                    return;
                }
                break;
            }
        }
    }
}


void BookStore::CheckOut(std::shared_ptr<Book> &book, int count) {
    std::cout<<"Price for "<<count<<" books: $"<<count*book->GetPrice()<<"\n";
    std::string name{}, lastName{}, confirm{};
    uint64_t cardNumber{};
    uint16_t secretCode{};
    std::cout<<"Enter your name: ";
    std::cin>>name;
    std::cout<<"Enter your last name: ";
    std::cin>>lastName;
    std::cout<<"Enter your card number: ";
    std::cin>>cardNumber;
    std::cout<<"Enter your secret code: ";
    std::cin>>secretCode;
    std::cout<<"Confirm the purchase(yes/no): ";
    std::cin>>confirm;
    if(confirm == "yes") {
        book->SetQuantity(-count);
        std::cout<<"You have successfully ordered "<<count<<" of "<<
        book->GetTitle()<<"\n";
        std::cout<<"Thank you for your order!\n\n";
    } else {
        std::cout<<"The order has been cancelled.\n\n";
    }
}
