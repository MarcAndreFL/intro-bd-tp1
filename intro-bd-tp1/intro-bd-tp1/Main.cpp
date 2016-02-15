#include "Database.h"
#include "Parsing.h"
#include "Request.h"
#include <iostream>

#define PAGE_MENU 0
#define PAGE_ISBN 1

bool PrintUI(int);
void RepeatChar(char, int);

void main(){
	Parsing parser;
	parser.DoParsing();
	Database::GetInstance()._bookTable;
	Database::GetInstance()._bookCopiesTable;
	Database::GetInstance()._bookLoansTable;
	Database::GetInstance()._borrowersTable;
	/*std::cout << "------------------------\n\tBORROWER LIST\n------------------------\n";
	for (std::map<unsigned int, Borrower>::iterator it = Database::GetInstance()._borrowersTable.begin(); it != Database::GetInstance()._borrowersTable.end(); it++){
		std::cout << "------------------------\n";
		std::cout << "Borrower Name: " << it->second.GetBorrowerName() << "\n";
		std::cout << "Borrower No: " << it->second.GetBorrowerNo() << "\n";
		std::cout << "Borrower Address: " << it->second.GetBorrowerAddress() << "\n";
		std::cout << "------------------------\n";
	}*/
	while (PrintUI(PAGE_MENU)) {}
}

bool PrintUI(int page) {
	Request resquester;

	system("cls");

	switch (page) {
		case PAGE_MENU:
			RepeatChar(' ', 32);
			std::cout << "LIBRARY DATABASE" << std::endl;
			RepeatChar('-', 80);
			std::cout << std::endl;

			std::cout << " 1. Every book from 1931" << std::endl;
			std::cout << " 2. Every copy of a particular book that are available" << std::endl;
			std::cout << " 3. Every borrower who has a copy of a particular book" << std::endl;
			std::cout << " 4. Every borrower who currently has a book in his possession" << std::endl;
			std::cout << " 5. Quit" << std::endl;

			std::cout << std::endl;
			RepeatChar('-', 80);
			std::cout << std::endl << " ";

			int io;
			std::cin >> io;

			if (std::cin.fail() || io > 5 || io < 1) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl << "Please Enter a number from 1 to 5" << std::endl;
				system("PAUSE");
			}
			else {
				switch (io) {
					case 1: {
						std::vector<std::string> booksName = resquester.BookFromYear(1931);
						for (unsigned int i = 0; i < booksName.size(); i++){
							std::cout << "Title:\t" << booksName[i] << "\n";
						}
						system("pause");
						break;
					}
					case 2: {
						std::vector<unsigned int> booksISBN = resquester.BookCopyAvailable(60725861);
						for (unsigned int i = 0; i < booksISBN.size(); i++){
							std::cout << "ISBN:\t" << booksISBN[i] << "\n";
						}
						system("pause");
						break;
					}
					case 3: {
						std::vector<std::string> borrowersWithBooksX = resquester.BorrowersWithXBook(60725861);
							for (unsigned int i = 0; i < borrowersWithBooksX.size(); i++){
							std::cout << "Borrower Name:\t" << borrowersWithBooksX[i] << "\n";
						}
						system("pause");
						break;
					}
					case 4: {
						std::vector<std::string> borrowersWithBooks = resquester.BorrowersWithBook();
						for (unsigned int i = 0; i < borrowersWithBooks.size(); i++){
							std::cout << "Borrower Name:\t" << borrowersWithBooks[i] << "\n";
						}
						system("pause");
						break;
					}
					case 5: return false;
				}
			}
			return true;
		
		case PAGE_ISBN:
			return true;

		return true;
	}
}

void RepeatChar(char c, int num) {
	for (int i = 0; i < num; i++) {
		std::cout << c;
	}
}