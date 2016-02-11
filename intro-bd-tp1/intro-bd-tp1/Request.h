#pragma once

#include <string>
#include <map>
#include <vector>
#include "Book.h"
#include "BookLoan.h"
#include "BookCopy.h"
#include "Borrower.h"
#include "Database.h"

class Request 
{
public:
	/* The title of every book of a year */
	std::vector<std::string> BookFromYear(int year)
	{
		std::map<unsigned int, Book> books = Database::GetInstance()._bookTable;
		std::vector<std::string> bookName;
		for (std::map<unsigned int, Book>::iterator it = books.begin(); it != books.end(); it++)
			{
				if (it->second.GetYear() == year) {
					bookName.push_back(it->second.GetTitle());
			}
		}
		return bookName;
	}

	/* Every copy of X book available */

	/*
	isbn dans BookCopy
	Dans bookloan, si date de retour < que date aujourd'hui
	*/
	std::vector<std::string> BookCopyAvailable(unsigned int bookISBN) 
	{
		std::map<unsigned int, BookCopy> booksCopy = Database::GetInstance()._bookCopiesTable;
		std::map<unsigned int, BookLoan> booksLoan = Database::GetInstance()._bookLoansTable;
		std::vector<unsigned int> CopyNo;

		for (std::map<unsigned int, BookCopy>::iterator it = booksCopy.begin(); it != booksCopy.end(); it++)
		{
			if (it->second.GetISBN() == bookISBN)
			{
				CopyNo.push_back(it->second.GetCopyNo());
			}
		}


		/*

		for (std::map<unsigned int, BookLoan>::iterator it = booksLoan.begin(); it != booksLoan.end(); it++)
		{
			if (it->second. == bookISBN)
			{
				CopyNo.push_back(it->second.GetCopyNo());
			}
		}





		return CopyNo;*/
	}

	/* The name of every member with X book */
	std::vector<std::string> BorrowersWithXBook(unsigned int bookISBN) 
	{

	}

	/* The name of every member with a book */
	std::vector<std::string> BorrowersWithBook(unsigned int bookISBN)
	{

	}
};