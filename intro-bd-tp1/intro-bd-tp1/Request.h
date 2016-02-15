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
#include <algorithm>


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
		std::unordered_map<BookLoanKey, BookLoan> booksLoan = Database::GetInstance()._bookLoansTable;
		std::vector<unsigned int> CopyNo;
		std::vector<unsigned int> CopyNoAvailable;
		
		struct tm newtime;
		__time64_t long_time;
		char timebuf[26];
		errno_t err;

		// Get time as 64-bit integer.
		_time64(&long_time);
		// Convert to local time.
		err = _localtime64_s(&newtime, &long_time);


		for (std::map<unsigned int, BookCopy>::iterator it = booksCopy.begin(); it != booksCopy.end(); it++)
		{
			if (it->second.GetISBN() == bookISBN)
			{
				CopyNo.push_back(it->second.GetCopyNo());
			}
		}

		for (std::unordered_map<BookLoanKey, BookLoan>::iterator it = booksLoan.begin(); it != booksLoan.end(); it++)
		{
			for (unsigned int i = 0; i < CopyNo.size(); i++){
				if (it->second.GetCopyNo() == CopyNo[i]){
					if (it->second.GetDateDue()._year < newtime.tm_year+1900){
						CopyNoAvailable.push_back(CopyNo[i]);
					}
					else if (it->second.GetDateDue()._year == newtime.tm_year + 1900){
						if (it->second.GetDateDue()._month < newtime.tm_mon + 1){
							CopyNoAvailable.push_back(CopyNo[i]);
						}
						else if (it->second.GetDateDue()._month == newtime.tm_mday+1){
							if (it->second.GetDateDue()._day < newtime.tm_mday){
								CopyNoAvailable.push_back(CopyNo[i]);
							}
						}
					}
				}
			}
		}
		//ON DELETE LES DOUBLONS DU VECTEUR
		std::sort(CopyNoAvailable.begin(), CopyNoAvailable.end());
		auto last = std::unique(CopyNoAvailable.begin(), CopyNoAvailable.end());
		CopyNoAvailable.erase(last, CopyNoAvailable.end());

		//PUIS ON OUTPUT LE VECTEUR
		return CopyNoAvailable;
	}

	/* The name of every member with X book */
	std::vector<std::string> BorrowersWithXBook(unsigned int bookISBN) 
	{
		std::map<unsigned int, BookCopy> booksCopy = Database::GetInstance()._bookCopiesTable;
		std::unordered_map<BookLoanKey, BookLoan> booksLoan = Database::GetInstance()._bookLoansTable;
		std::map<unsigned int, Borrower> borrower = Database::GetInstance()._borrowersTable;
		std::vector<unsigned int> CopyNo;
		std::vector<unsigned int> BorrowerNo;
		std::vector<std::string> BorrowerName;



		struct tm newtime;
		__time64_t long_time;
		char timebuf[26];
		errno_t err;

		// Get time as 64-bit integer.
		_time64(&long_time);
		// Convert to local time.
		err = _localtime64_s(&newtime, &long_time);


		for (std::map<unsigned int, BookCopy>::iterator it = booksCopy.begin(); it != booksCopy.end(); it++)
		{
			if (it->second.GetISBN() == bookISBN)
			{
				CopyNo.push_back(it->second.GetCopyNo());
			}
		}

		for (std::unordered_map<BookLoanKey, BookLoan>::iterator it = booksLoan.begin(); it != booksLoan.end(); it++)
		{
			for (unsigned int i = 0; i < CopyNo.size(); i++){
				if (it->second.GetCopyNo() == CopyNo[i]){
					if (it->second.GetDateDue()._year > newtime.tm_year + 1900){
						BorrowerNo.push_back(it->second.GetBorrowerNo());
					}
					else if (it->second.GetDateDue()._year == newtime.tm_year + 1900){
						if (it->second.GetDateDue()._month > newtime.tm_mon + 1){
							BorrowerNo.push_back(it->second.GetBorrowerNo());
						}
						else if (it->second.GetDateDue()._month == newtime.tm_mon + 1){
							if (it->second.GetDateDue()._day > newtime.tm_mday){
								BorrowerNo.push_back(it->second.GetBorrowerNo());
							}
						}
					}
				}
			}
		}
		if (BorrowerNo.size() > 0){
			for (std::map<unsigned int, Borrower>::iterator it = borrower.begin(); it != borrower.end(); it++)
			{
				for (unsigned int i = 0; i < BorrowerNo.size(); i++){
					if (it->second.GetBorrowerNo() == BorrowerNo[i])
					{
						BorrowerName.push_back(it->second.GetBorrowerName());
					}
				}
			}
		}
		return BorrowerName;
	}

	/* The name of every member with a book */
	std::vector<std::string> BorrowersWithBook()
	{
		std::unordered_map<BookLoanKey, BookLoan> booksLoan = Database::GetInstance()._bookLoansTable;
		std::map<unsigned int, Borrower> borrower = Database::GetInstance()._borrowersTable;
		std::vector<unsigned int> BorrowerNo;
		std::vector<std::string> BorrowerName;

		struct tm newtime;
		__time64_t long_time;
		char timebuf[26];
		errno_t err;

		// Get time as 64-bit integer.
		_time64(&long_time);
		// Convert to local time.
		err = _localtime64_s(&newtime, &long_time);

		for (std::unordered_map<BookLoanKey, BookLoan>::iterator it = booksLoan.begin(); it != booksLoan.end(); it++)
		{
			if (it->second.GetDateDue()._year > newtime.tm_year + 1900){
				BorrowerNo.push_back(it->second.GetBorrowerNo());
			}
			else if (it->second.GetDateDue()._year == newtime.tm_year + 1900){
				if (it->second.GetDateDue()._month > newtime.tm_mon + 1){
					BorrowerNo.push_back(it->second.GetBorrowerNo());
				}
				else if (it->second.GetDateDue()._month == newtime.tm_mon + 1){
					if (it->second.GetDateDue()._day > newtime.tm_mday){
						BorrowerNo.push_back(it->second.GetBorrowerNo());
					}
				}
			}
		}

		for (std::map<unsigned int, Borrower>::iterator it = borrower.begin(); it != borrower.end(); it++)
		{
			for (unsigned int i = 0; i < BorrowerNo.size(); i++){
				if (it->second.GetBorrowerNo() == BorrowerNo[i])
				{
					BorrowerName.push_back(it->second.GetBorrowerName());
				}
			}
		}


		//ON DELETE LES DOUBLONS DU VECTEUR
		std::sort(BorrowerName.begin(), BorrowerName.end());
		auto last = std::unique(BorrowerName.begin(), BorrowerName.end());
		BorrowerName.erase(last, BorrowerName.end());

		return BorrowerName;
	}
};