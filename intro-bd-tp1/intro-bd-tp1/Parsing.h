#pragma once
#include <String>
#include <Vector>
#include <fstream>
#include <iostream>
#include "Database.h"


class Parsing
{
private:
	void DoBookParsing();
	void DoBookCopyParsing();
	void DoBookLoanParsing();
	void DoBorrowerParsing();
public:
	Parsing();

	void DoParsing();

	~Parsing();
};

