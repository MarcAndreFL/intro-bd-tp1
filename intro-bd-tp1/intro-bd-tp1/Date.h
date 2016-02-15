#pragma once


struct Date{
	int _year;
	int _month;
	int _day;

	bool operator<(const Date &d) const
	{
		if (_year < d._year && _month < d._month && _day < d._day){
			return true;
		}
		else{
			return false;
		}
		
	}

	bool operator==(const Date &d) const
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
};