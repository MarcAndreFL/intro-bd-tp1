#include "Parsing.h"

Parsing::Parsing()
{

}


Parsing::~Parsing()
{

}

Parsing::Parsing()
{
	std::ifstream file("file.csv"); // declare file stream: http://www.cplusplus.com/reference/iostream/ifstream/
	std::string value;
	while (file.good())
	{
		std::getline(file, value, ','); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
		std::cout << std::string(value, 1, value.length() - 2); // display value removing the first and the last character from it
	}
}

/*	
	std::vector<std::string>   result;
	std::string                line;
	std::getline(str, line);

	std::stringstream          lineStream(line);
	std::string                cell;

	while (std::getline(lineStream, cell, ','))
	{
		result.push_back(cell);
		}
		
*/