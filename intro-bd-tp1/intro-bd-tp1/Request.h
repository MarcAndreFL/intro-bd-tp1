#pragma once

#include <string>
#include <map>
#include <vector>
#include <ctime>
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

	std::vector<unsigned int> BookCopyAvailable(unsigned int bookISBN)
	{
		std::map<unsigned int, BookCopy> booksCopy = Database::GetInstance()._bookCopiesTable;
		std::map<BookLoanKey, BookLoan> booksLoan = Database::GetInstance()._bookLoansTable;
		std::vector<unsigned int> CopyNo;
		std::vector<unsigned int> CopyNoAvailable;
		time_t t = time(0);
		struct tm *now = localtime(&t);


		for (std::map<unsigned int, BookCopy>::iterator it = booksCopy.begin(); it != booksCopy.end(); it++)
		{
			if (it->second.GetISBN() == bookISBN)
			{
				CopyNo.push_back(it->second.GetCopyNo());
			}
		}

		for (std::map<BookLoanKey, BookLoan>::iterator it = booksLoan.begin(); it != booksLoan.end(); it++)
		{
			for (int i = 0; i < CopyNo.size(); i++){
				if (it->second.GetCopyNo() == CopyNo[i]){
					if (it->second.GetDateDue()._year <= now->tm_year + 1900 && it->second.GetDateDue()._month <= now->tm_mon + 1 && it->second.GetDateDue()._day <= now->tm_mday){
						CopyNoAvailable.push_back(CopyNo[i]);
					}
				}
			}
		}
		return CopyNoAvailable;
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