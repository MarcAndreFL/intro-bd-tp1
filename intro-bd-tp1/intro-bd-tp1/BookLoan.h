#pragma once

#include "Date.h"


class BookLoan{
	private:
		unsigned int _copyNo;
		Date* _dateOut;
		Date* _dateDue;
		unsigned int _borrowerNo;
	public:
		//Getters
		unsigned int GetCoppyNo(){ return _copyNo; };
		Date* GetDateOut(){ return _dateOut; };
		Date* GetDateDue(){ return _dateDue; };
		unsigned int GetBorrowerNo(){ return _borrowerNo; };

		BookLoan(unsigned int copyNo, Date* dateOut, Date* dateDue, unsigned int borrowerNo){
			_copyNo = copyNo;
			_dateOut = dateOut;
			_dateDue = dateDue;
			_borrowerNo = borrowerNo;
		}
		~BookLoan(){
			delete _dateOut;
			delete _dateDue;
		}
};