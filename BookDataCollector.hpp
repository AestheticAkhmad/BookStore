//
//  BookDataCollector.hpp
//  BookStore
//
//  Created by Akhmad Oripov  on 14/01/2023.
//

#ifndef BookDataCollector_hpp
#define BookDataCollector_hpp

#include "Book.hpp"

#include <vector>
#include <map>
#include <memory>

class BookDataCollector {
private:
public:
    BookDataCollector(std::vector<std::shared_ptr<Book>> &books, std::map<std::string, std::shared_ptr<Book>> &booksByTitle,
                      std::map<uint64_t, std::shared_ptr<Book>> &booksByISBN);
};

#endif /* BookDataCollector_hpp */
