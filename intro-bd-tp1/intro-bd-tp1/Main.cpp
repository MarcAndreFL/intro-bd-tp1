#include "Database.h"
#include <iostream>

void main(){
	Book myBook =  Book(1, "allo", "hello", 1994);
	Database::GetInstance()._bookTable.insert(std::pair<unsigned int, Book>(myBook.GetISBN(), myBook));
	std::cout << Database::GetInstance()._bookTable.at(myBook.GetISBN()).GetTitle();
	system("PAUSE");
}