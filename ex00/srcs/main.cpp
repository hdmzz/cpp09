/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:32:58 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/12/29 17:21:29 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

void checkArgs(int ac) {
    if (ac != 2)
        throw (std::runtime_error("Error argmuments, programm need a file to be open"));
    return ;
}

int checkDate(std::string date) {
    
}

int checkValue(std::string value) {
    
}

void checkDatabase(std::string databasePath) {
    struct stat sb;

    if (stat(databasePath.c_str(), &sb) != 0)
        throw (std::runtime_error("Stat"));
    switch (sb.st_mode & S_IFMT) {
        case S_IFDIR: throw(std::runtime_error("Arguments is a directory"));
        case S_IXUSR: throw(std::runtime_error("Argument is binary"));
    }
    std::ifstream fs(databasePath.c_str());//ouverture du ifstream ici pas besoin de plus 
    if (!fs.is_open())
        throw (std::runtime_error("Error Database"));

    std::string line;
    while (std::getline(fs, line)) {
        //verifier que le format date | value est repecté
        std::istringstream iss(line);
        //check if each line contqins one |
        std::string::size_type pos = line.find('|');
        //check if pos isnt at the end of the line
        if (pos == std::string::npos )
            std::cerr << "Not a good format in line : " << line << std::endl;
        //get the date check the for;at YYYY-MM-DD
        if (!checkDate((line.substr(0, pos))) || !checkValue((line.substr(pos + 1))))
            std::cerr << "invalid format in the line : " << line << std::endl;
        else
            std::cout << line << std::endl;
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
