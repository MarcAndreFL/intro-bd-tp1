#pragma once


class Date{
	private:
		int _year;
		int _month;
		int _day;
	public:

		Date(int year, int month, int day){
			_year = year;
			_month = month;
			_day = day;
		};

		//Getters
		int GetYear(){ return _year; };
		int GetMonth(){ return _month; };
		int GetDay(){ return _day; };

};