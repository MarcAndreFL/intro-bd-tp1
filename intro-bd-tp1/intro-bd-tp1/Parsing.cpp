#include "Parsing.h"

Parsing::Parsing()
{

}


Parsing::~Parsing()
{

}

Parsing::Parsing()
{
	std::ifstream file("file.csv");
	std::string value;
	while (file.good())
	{
		std::getline(file, value, ',');
		
		
		
		//std::cout << std::string(value, 1, value.length() - 2);
	}
}


Book myBook = Book(1, "allo", "hello", 1994);
Database::GetInstance()._bookTable.insert(std::pair<unsigned int, Book>(myBook.GetISBN(), myBook));
std::cout << Database::GetInstance()._bookTable.at(myBook.GetISBN()).GetTitle();