#include "Database.h"
#include "Parsing.h"
#include <iostream>

void main(){
	Parsing parser;
	parser.DoParsing();
	Database::GetInstance()._bookTable;
	Database::GetInstance()._bookCopiesTable;
	Database::GetInstance()._bookLoansTable;
	Database::GetInstance()._borrowersTable;
	std::cout << "------------------------\n\tBORROWER LIST\n------------------------\n";
	for (std::map<unsigned int, Borrower>::iterator it = Database::GetInstance()._borrowersTable.begin(); it != Database::GetInstance()._borrowersTable.end(); it++){
		std::cout << "------------------------\n";
		std::cout << "Borrower Name: " << it->second.GetBorrowerName() << "\n";
		std::cout << "Borrower No: " << it->second.GetBorrowerNo() << "\n";
		std::cout << "Borrower Address: " << it->second.GetBorrowerAddress() << "\n";
		std::cout << "------------------------\n";
	}
	system("PAUSE");
}