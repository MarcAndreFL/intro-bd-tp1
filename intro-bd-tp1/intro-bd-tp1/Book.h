#include <string>


class Book{
	private:
		unsigned int _iSBN;
		std::string _title;
		std::string _edition;
		int _year;

	public:
		Book(unsigned int isbn, std::string title, std::string edition, int year){
			_iSBN = isbn;
			_title = title;
			_edition = edition;
			_year = year;
		};

		unsigned int GetISBN(){ return _iSBN; };
		std::string GetTitle(){ return _title; };
		std::string GetEdition(){ return _edition; };
		int GetYear(){ return _year; };
};