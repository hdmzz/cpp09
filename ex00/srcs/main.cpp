#include <iostream>
#include <fstream>
#include <string>
#include "BitcoinExchange.hpp"
#include "utils.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		if (argc > 2)
			std::cerr << "Error: too many arguments." << std::endl;
		else
			std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	BitcoinExchange btc = BitcoinExchange("input/data.csv");
	try
	{
		btc.constructDatabase();
	}
	catch (BitcoinExchange::CantReadDataFile &e)
	{
		std::cerr << e.what() << " (" << btc.dbPath() << ")" << std::endl;
		return (1);
	}


	// Open file
	std::string line;
	std::ifstream inputfile(argv[1]);

	if (!inputfile.is_open())
	{
		std::cerr << "Error: could not open file (" << argv[1] << ")" << std::endl;
		return (1);
	}

	// Read line by line
	int ctr = -1;
	while (getline(inputfile,line))
	{
		ctr++;
		if (ctr == 0)
			continue;

		bool ignore = false;

		// Split on |
		char *ptr;
		ptr = std::strtok((char *)line.c_str(), " | ");
		std::string date;
		std::string value;
		while (ptr != NULL)
		{
			if (date.empty())
				date = ptr;
			else if (value.empty())
				value = ptr;
			else
				ignore = true;
			// std::cout << ptr  << std::endl;
			ptr = strtok (NULL, " | ");
		}

		// Check date format
		if (!checkDateFormat(date) && !ignore)
		{
			std::cerr << "Error: Incorrect date format (" << date << ")" << std::endl;
			ignore = true;
		}
		// Check value format
		if (!checkValue(value) && !ignore)
		{
			std::cerr << "Error: Incorrect value format (" << value << ")" << std::endl;
			ignore = true;
		}

		if (!ignore && strToFloat(value) > 1000)
		{
			std::cerr << "Error: Too large a number (" << value << ")" << std::endl;
			ignore = true;
		}

		if (!ignore) {
			float result = strToFloat(value) * btc.getRate(date);
			std::cout << date << " => " << value << " = " << result << std::endl;
		}

	}
	inputfile.close();
}
