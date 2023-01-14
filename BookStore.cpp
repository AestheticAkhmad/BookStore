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
