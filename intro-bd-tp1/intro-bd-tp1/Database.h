#pragma once
#include <map>
#include "Book.h"
#include "Date.h"
#include "BookCopy.h"
#include "Borrower.h"
#include "BookLoan.h"
#include <unordered_map>

namespace std
{
	template <>
	struct hash<BookLoanKey>
	{
		size_t operator()(const BookLoanKey& k) const
		{
			// Compute individual hash values for two data members and combine them using XOR and bit shifting
			return ((hash<unsigned int>()(k.copyNo)) ^ (hash<unsigned int>()(k.date._year)) ^ (hash<unsigned int>()(k.date._month)) ^ (hash<unsigned int>()(k.date._day)) << 1 >> 1);
		}
	};
}

class Database{
	
	public:
		std::map<unsigned int, Book> _bookTable;
		std::map<unsigned int, BookCopy> _bookCopiesTable;
		std::unordered_map<BookLoanKey, BookLoan> _bookLoansTable;
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

