/*#include "Parsing.h"


Parsing::Parsing()
{

}


Parsing::~Parsing()
{

}

void Parsing::DoParsing(){
	std::cout << "-----------------------------------------------\n\tDOING BOOK PARSING\n------------------------------------------------\n";
	DoBookParsing();
	std::cout << "-----------------------------------------------\n\tBOOK PARSING OVER\n------------------------------------------------\n";

	std::cout << "-----------------------------------------------\n\tDOING BOOKCOPY PARSING\n------------------------------------------------\n";
	DoBookCopyParsing();
	std::cout << "-----------------------------------------------\n\tBOOKCOPY PARSING OVER\n------------------------------------------------\n";

	std::cout << "-----------------------------------------------\n\tDOING BOOKLOAN PARSING\n------------------------------------------------\n";
	DoBookLoanParsing();
	std::cout << "-----------------------------------------------\n\tBOOKLOAN PARSING OVER\n------------------------------------------------\n";

	std::cout << "------------------------------------------------\n\tDOING BORROWER PARSING\n------------------------------------------------\n";
	DoBorrowerParsing();
	std::cout << "------------------------------------------------\n\tBORROWER PARSING OVER\n------------------------------------------------\n";
}

void Parsing::DoBookParsing(){
	std::ifstream file("Book.csv");
	std::string value;
	while (file.good())
	{
		std::getline(file, value, ',');
		if (!file.eof()){ //si on n'a pas atteint le caractère vide à la fin
			unsigned int isbn = std::stoi(value);
			//std::cout << "isbn to add: " << isbn << "\t";
			std::getline(file.ignore(1), value, '"'); //on ignore le premier "
			std::string name = value;
			//std::cout << "name to add: " << name << "\t";
			std::getline(file.ignore(1), value, ','); //on ignore la première virgule
			std::string edition = value;
			//std::cout << "edition to add: " << edition << "\t";
			std::getline(file, value, '\n');
			unsigned int year = std::stoi(value);
			//std::cout << "year to add: " << year << "\n\n";


			Book currentBook = Book(isbn, name, edition, year);
			Database::GetInstance()._bookTable.insert(std::pair<unsigned int, Book>(currentBook.GetISBN(), currentBook));
		}
	}
}

void Parsing::DoBookCopyParsing(){
	std::ifstream file("BookCopy.csv");
	std::string value;
	while (file.good())
	{
		if (file.peek() == '\n') file.get();
		std::getline(file,  value, ',');
		if (!file.eof()){ //si on n'a pas atteint le caractère vide à la fin
			unsigned int copyNo = std::stoi(value);
			//std::cout << "copyNo to add: " << copyNo << "\t";
			std::getline(file.ignore(1), value, '"'); //on ignore le premier "
			unsigned int isbn = std::stoi(value);
			//std::cout << "isbn to add: " << isbn << "\t";
			std::getline(file.ignore(2), value, '"'); //on ignore la première virgule et le "
			bool available = value=="true";
			//std::cout << "availability: " << available << "\n\n";


			BookCopy currentBookCopy = BookCopy(copyNo, isbn, available);
			Database::GetInstance()._bookCopiesTable.insert(std::pair<unsigned int, BookCopy>(currentBookCopy.GetCopyNo(), currentBookCopy));
		}
	}
}

void Parsing::DoBookLoanParsing(){
	std::ifstream file("BookLoan.csv");
	std::string value;
	while (file.good())
	{
		if (file.peek() == '\n') file.get();
		std::getline(file, value, ',');
		if (!file.eof()){ //si on n'a pas atteint le caractère vide à la fin
			//CopyNumber
			unsigned int copyNo = std::stoi(value);
			//std::cout << "copyNo to add: " << copyNo << "\t";

			//Date OUT
			std::getline(file.ignore(1), value, '-'); //on ignore le premier "
			unsigned int yearOut = std::stoi(value);
			std::getline(file, value, '-'); //on ignore le premier "
			unsigned int monthOut = std::stoi(value);
			std::getline(file, value, '"'); //on ignore le premier "
			unsigned int dayOut = std::stoi(value);

			//std::cout << "dateOut to add: " << yearOut << "-" << monthOut << "-" << dayOut << "\t";

			//Date IN
			std::getline(file.ignore(2), value, '-'); //on ignore le premier "
			unsigned int yearIn = std::stoi(value);
			std::getline(file, value, '-'); //on ignore le premier "
			unsigned int monthIn = std::stoi(value);
			std::getline(file, value, '"'); //on ignore le premier "
			unsigned int dayIn = std::stoi(value);

			//std::cout << "dateIn to add: " << yearIn << "-" << monthIn << "-" << dayIn << "\t";

			//BorrowerID
			std::getline(file.ignore(1), value, '\n'); //on ignore le premier "
			unsigned int borrowerID = std::stoi(value);

			//std::cout << "borrowerID to add: " << borrowerID << "\n\n";


			BookLoan currentBookLoan = BookLoan(copyNo, yearOut, monthOut, dayOut, yearIn, monthIn, dayIn, borrowerID);
			BookLoanKey bKey = BookLoanKey(currentBookLoan.GetCopyNo(), currentBookLoan.GetDateOut());
			Database::GetInstance()._bookLoansTable.insert(std::make_pair(bKey, currentBookLoan));
		}
	}
}

void Parsing::DoBorrowerParsing(){
	std::ifstream file("Borrower.csv");
	std::string value;
	while (file.good())
	{
		if (file.peek() == '\n') file.get();
		std::getline(file, value, ',');
		if (!file.eof()){ //si on n'a pas atteint le caractère vide à la fin
			//Borrower ID
			unsigned int borrowerID = std::stoi(value);
			//std::cout << "borrowerID to add: " << borrowerID << "\t";

			//Borrower Name
			std::getline(file.ignore(1), value, '"'); //on ignore le premier "
			std::string borrowerName = value;

			//std::cout << "borrowerName to add: " << borrowerName << "\t";

			//BorrowerAddress
			std::getline(file.ignore(2), value, '"'); //on ignore le virgule suivi d'un guillemet
			std::string borrowerAddress = value;
			//std::cout << "borrowerAddress to add: " << borrowerAddress << "\n\n";



			Borrower currentBorrower = Borrower(borrowerID, borrowerName, borrowerAddress);
			Database::GetInstance()._borrowersTable.insert(std::make_pair(borrowerID, currentBorrower));
		}
	}
}*/