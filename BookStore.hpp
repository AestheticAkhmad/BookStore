//
//  BookStore.hpp
//  BookStore
//
//  Created by Akhmad Oripov  on 14/01/2023.
//

#ifndef BookStore_hpp
#define BookStore_hpp

#include "Book.hpp"
#include "BookDataCollector.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <map>



class BookStore {
private:
    std::vector<std::shared_ptr<Book>> books{};
    std::map<std::string, std::shared_ptr<Book>> booksByTitle{};
    std::map<uint64_t, std::shared_ptr<Book>> booksByISBN{};
public:
    BookStore();
    void ListAll() const;
    void FindBook(const std::string &title) const;
    void FindBook(const uint64_t ISBN) const;
    
};


#endif /* BookStore_hpp */
