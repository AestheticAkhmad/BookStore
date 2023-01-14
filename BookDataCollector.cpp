//  By AestheticAkhmad
//  Created by Akhmad on 14/01/2023.

#include "BookDataCollector.hpp"

BookDataCollector::BookDataCollector(std::vector<std::shared_ptr<Book>> &books, std::map<std::string, std::shared_ptr<Book>> &booksByTitle,
                                     std::map<uint32_t, std::shared_ptr<Book>> &booksByISBN) {
    std::string line{};
    std::string fileName = "bookList.txt";
    std::fstream dataStream;
    dataStream.open(fileName);
    
    while(getline(dataStream, line)) {
        std::string title{}, author{};
        uint32_t ISBN{};
        int price{}, quantity{};
        std::istringstream buffer(line);
        buffer>>title>>author>>ISBN>>price>>quantity;
        Book newBook(title, author, price, ISBN, quantity);
        auto newBook_ptr = std::make_shared<Book>(newBook);
        books.push_back(newBook_ptr);
        
        auto originalTitle = books.back()->GetTitle();
        std::string editedTitle;
        editedTitle.reserve(originalTitle.size());
        std::remove_copy_if(
            begin(originalTitle), end(originalTitle),
            std::back_inserter(editedTitle),
            [l = std::locale{}](auto ch) { return std::ispunct(ch, l); }
        );
        
        booksByTitle.insert(make_pair(editedTitle, books.back()));
        booksByISBN.insert(make_pair(books.back()->GetISBN(), books.back()));
        
    }
    dataStream.close();
}
