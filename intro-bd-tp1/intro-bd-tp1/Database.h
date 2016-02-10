#pragma once
#include <map>
#include "Book.h"
#include "Date.h"
#include "BookCopy.h"
#include "Borrower.h"
#include "BookLoan.h"

class Database{

	public:
		std::map<unsigned int, Book> _bookTable;
		std::map<unsigned int, BookCopy> _bookCopiesTable;
		std::map<unsigned int, BookLoan> _bookLoansTable;
		std::map<unsigned int, Borrower> _borrowersTable;
		static Database& GetInstance(){
			static Database instance;
			return instance;
		}

	private:
		Database(){};
		Database(Database const&);
		void operator=(Database const&);
		
};