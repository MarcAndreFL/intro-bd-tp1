#pragma once
#include <string>



class Borrower{
	private:
		unsigned int _borrowerNo;
		std::string _borrowerName;
		std::string _borrowerAddress;
	public:
		//Getters
		unsigned int GetBorrowerNo(){ return _borrowerNo; };
		std::string GetBorrowerName(){ return _borrowerName; };
		std::string GetBorrowerAddress(){ return _borrowerAddress; };

		Borrower(unsigned int borrowerNo, std::string borrowerName, std::string borrowerAddress){
			_borrowerNo = borrowerNo;
			_borrowerName = borrowerName;
			_borrowerAddress = borrowerAddress;
		}
};