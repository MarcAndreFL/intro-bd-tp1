#pragma once

#include "Date.h"
struct BookLoanKey
{
	BookLoanKey(unsigned int i, Date d)
	{
		this->copyNo = i;
		this->date = d;
	}
	unsigned int copyNo;
	Date date;

	bool operator<(const BookLoanKey& k) const
	{
		bool yearCompare = this->date._year == k.date._day;
		bool monthCompare = this->date._month == k.date._month;
		bool dayCompare = this->date._day == k.date._day;
		bool indexCompare = this->copyNo == k.copyNo;
		if (yearCompare && monthCompare && dayCompare && indexCompare){
			return true;
		}
		else{
			return false;
		}
	}
};

class BookLoan{
	private:
		unsigned int _copyNo;
		Date _dateOut;
		Date _dateDue;
		unsigned int _borrowerNo;
	public:
		//Getters
		unsigned int GetCopyNo(){ return _copyNo; };
		Date GetDateOut(){ return _dateOut; };
		Date GetDateDue(){ return _dateDue; };
		unsigned int GetBorrowerNo(){ return _borrowerNo; };

		BookLoan(unsigned int copyNo, unsigned int yearOut, unsigned int monthOut, unsigned int dayOut,
			unsigned int yearDue, unsigned int monthDue, unsigned int dayDue, unsigned int borrowerNo){
			_copyNo = copyNo;
			_dateOut._year = yearOut;
			_dateOut._month = monthOut;
			_dateOut._day = dayOut;
			_dateDue._year = yearDue;
			_dateDue._month = monthDue;
			_dateDue._day = dayDue;
			_borrowerNo = borrowerNo;
		}
};