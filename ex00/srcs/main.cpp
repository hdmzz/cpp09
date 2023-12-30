/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:32:58 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/12/29 23:33:02 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

//utilisation remove if white space


void checkArgs(int ac) {
    if (ac != 2)
        throw (std::runtime_error("Error argmuments, programm need a file to be open"));
    return ;
}

//get the date check the for;at YYYY-MM-DD
int checkDate(std::string date) {
     int day, month, year;

     if (sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3)
         std::cerr << "date probleme : " << date << std::endl;
     else if (year < 1900 || year > 2099 || month < 1 || month > 12 || day < 1 || day > 31)
         std::cerr << "Invalid date format in line: " << date << '\n';
     else {
         std::cout << "date = " << year << "-" << month << "-" << day << std::endl;
     }
    return (1);
}

int checkValue(std::string valueStr) {
    int intValue;
    float floatValue;

    if (sscanf(valueStr.c_str(), "%d", &intValue) == 1)
        return 
    return (1);
}

//function to trim spaces from input
bool isSpaceOrTab(char c) {
    return (c == ' ' || c == '\t');
}

void checkDatabase(std::string databasePath) {
    struct stat sb;

    if (stat(databasePath.c_str(), &sb) != 0)
        throw (std::runtime_error("Stat"));
    switch (sb.st_mode & S_IFMT) {
        case S_IFDIR: throw(std::runtime_error("Arguments is a directory"));
        case S_IXUSR: throw(std::runtime_error("Argument is binary"));
    }

    //ouverture du ifstream ici pas besoin de plus 
    std::ifstream fs(databasePath.c_str());
    
    if (!fs.is_open())
        throw (std::runtime_error("Error Database"));

    std::string line;
    
    while (std::getline(fs, line)) {
        
        //verifier que le format date | value est repecté
        //trim whites saces line  >> YYYY-MM-DD|VV
        
        line.erase(std::remove_if(line.begin(), line.end(), isSpaceOrTab), line.end());
        //check if each line contqins one |
        std::string::size_type pos = line.find('|'); 
        ////check if pos isnt at the end of the line if so >>> fuck off
        if (pos == std::string::npos )
            std::cerr << "Not a good format in line : " << line << std::endl;
        else if (!checkDate((line.substr(0, pos))) || !checkValue((line.substr(pos + 1))))
            std::cerr << "invalid format in the line : " << line << std::endl;
        else
            std::cout << "check database after the checks" << line << std::endl;
    }
    return;
}

int main(int ac, char **av) {
    BitcoinExchange btc;
    try {
        checkArgs(ac);
        //parser la base de données , la recup et la foutre ds un map puis recup un fichier celui de l' rgument et le faire c
        checkDatabase(av[1]);
    } catch (std::exception & e) {
        std::cerr << "Error " << e.what() << std::endl;
    }
    
    
}
