#pragma once

#include <string>
#include <map>
#include <vector>
#include "Book.h"
#include "BookLoan.h"
#include "BookCopy.h"
#include "Borrower.h"

class Request {
public:
	/* The title of every book of a year */
	std::vector<std::string> BookFromYear(int year, std::map<unsigned int, Book> books) {
		std::vector<std::string> bookName;
		for (int i = 0; i < books.count; i++) {
			if (books[i].GetYear() == year) {
				bookName.push_back(books[i].GetTitle());
			}
		}

		return bookName;
	}

	/* Every copy of X book available */
	std::vector<std::string> BookCopyAvailable(unsigned int bookISBN) {

	}

	std::vector<std::string> BorrowersWithBook(unsigned int bookISBN) {

	}
};