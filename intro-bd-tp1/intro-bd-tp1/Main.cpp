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
	while (PrintUI(PAGE_MENU)) {}
}

inline bool PrintUI(int page) {
	Request resquester;

	system("cls");

	switch (page) {
		case PAGE_MENU:
			RepeatChar(' ', 32);
			std::cout << "LIBRARY DATABASE" << std::endl;
			RepeatChar('-', 80);
			std::cout << std::endl;

			std::cout << " 1. Every book from a particular year" << std::endl;
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
				int input;
				switch (io) {
					case 1: {
						std::cout << "Please  Enter a year: ";
						std::cin >> input;
						std::vector<std::string> booksName = resquester.BookFromYear(input);
						if (booksName.size() == 0) std::cout << "There is no book from " << input << " in our database\n";
						for (unsigned int i = 0; i < booksName.size(); i++){
							std::cout << "Title:\t" << booksName[i] << "\n";
						}
						system("pause");
						break;
					}
					case 2: {
						std::cout << "Please  Enter a ISBN: ";
						std::cin >> input;
						std::vector<unsigned int> booksISBN = resquester.BookCopyAvailable(input);
						if (booksISBN.size() == 0) std::cout << "There is no book with the ISBN " << input << " available\n";
						for (unsigned int i = 0; i < booksISBN.size(); i++){
							std::cout << "Copy Number:\t" << booksISBN[i] << "\n";
						}
						system("pause");
						break;
					}
					case 3: {
						std::cout << "Please  Enter a ISBN: ";
						std::cin >> input;
						std::vector<std::string> borrowersWithBooksX = resquester.BorrowersWithXBook(input);
						if (borrowersWithBooksX.size() == 0) std::cout << "There is no current borrower for the book with ISBN " << input << "\n";
							for (unsigned int i = 0; i < borrowersWithBooksX.size(); i++){
							std::cout << "Borrower Name:\t" << borrowersWithBooksX[i] << "\n";
						}
						system("pause");
						break;
					}
					case 4: {
						std::vector<std::string> borrowersWithBooks = resquester.BorrowersWithBook();
						if (borrowersWithBooks.size() == 0) std::cout << "There is no current borrower \n";
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

inline void RepeatChar(char c, int num) {
	for (int i = 0; i < num; i++) {
		std::cout << c;
	}
}