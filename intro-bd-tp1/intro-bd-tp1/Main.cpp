#include "Database.h"
#include <iostream>

void main(){
	Book myBook = Book(1, "allo", "hello", 1994);
	Database::GetInstance()._bookTable.insert(std::pair<unsigned int, Book>(myBook.GetISBN(), myBook));
	std::cout << Database::GetInstance()._bookTable.at(myBook.GetISBN()).GetTitle();


	system("PAUSE");

	BookLoan myLoanedBook = BookLoan(2, 1994, 4, 1, 1995, 4, 1, 10);
	BookLoanKey bookLoanKey = BookLoanKey(myLoanedBook.GetCopyNo(), myLoanedBook.GetDateOut());
	Database::GetInstance()._bookLoansTable.insert(std::make_pair(bookLoanKey,myLoanedBook));
	std::cout << Database::GetInstance()._bookLoansTable.at(bookLoanKey).GetCopyNo();

	system("PAUSE");
}