#ifndef BITCOINEXCHANGE_CLASS_H
# define BITCOINEXCHANGE_CLASS_H

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <map>
# include <ctime>
# include <sstream>
# include <utility>

class BitcoinExchange {
private:
	std::string _db_path;//database path
	std::map<std::string, float> _db;//container map stock key value

public:
//coplien canonical form
	BitcoinExchange(void);
	BitcoinExchange(const std::string db_path);
	BitcoinExchange(const BitcoinExchange &src);
	~BitcoinExchange(void);

	BitcoinExchange	&operator =(const BitcoinExchange &src);

	void constructDatabase(void);
	std::string dbPath(void) const;
	float getRate(std::string date);

	class CantReadDataFile: public std::exception {
	public:
		virtual const char* what(void) const throw();
	};
};

#endif
