//
//  BookDataCollector.cpp
//  BookStore
//
//  Created by Akhmad Oripov  on 14/01/2023.
//

#include "BookDataCollector.hpp"

BookDataCollector::BookDataCollector(std::vector<std::shared_ptr<Book>> &books, std::map<std::string, std::shared_ptr<Book>> &booksByTitle,
                                     std::map<uint32_t, std::shared_ptr<Book>> &booksByISBN) {
    std::string line{};
    std::string fileName = "bookList.txt";
    std::fstream dataStream;
    dataStream.open(fileName);
    while(getline(dataStream, line)) {
        std::string title{};
        uint32_t ISBN{};
        int price{};
        std::istringstream buffer(line);
        buffer>>title>>ISBN>>price;
        Book newBook(title, price, ISBN);
        auto newBook_ptr = std::make_shared<Book>(newBook);
        books.push_back(newBook_ptr);
        booksByTitle.insert(make_pair(books.back()->GetTitle(), books.back()));
        booksByISBN.insert(make_pair(books.back()->GetISBN(), books.back()));
    }
    dataStream.close();
}
