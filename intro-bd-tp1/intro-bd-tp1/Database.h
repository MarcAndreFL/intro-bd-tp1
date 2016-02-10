#pragma once
#include <map>
#include "Book.h"
#include "Date.h"
#include "BookCopy.h"
#include "Borrower.h"
#include "BookLoan.h"

class Database{

	private:
		std::map<Book, unsigned int> _bookTable;
		std::map<BookCopy, unsigned int> _bookCopiesTable;
		std::map<BookLoan, unsigned int> _bookLoansTable;
		std::map<Borrower, unsigned int> _borrowersTable;

	public:

};