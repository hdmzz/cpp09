/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:32:58 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/12/22 10:11:33 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

void checkArgs(int ac) {
    if (ac != 2)
        throw (std::runtime_error("Error argmuments, programm need a file to be open"));
    return ;
}

void checkDatabase(std::string databasePath) {
    struct stat sb;

    if (stat(databasePath.c_str(), &sb) != 0)
        throw (std::runtime_error("Stat"));
    switch (sb.st_mode & S_IFMT) {
        case S_IFDIR: throw(std::runtime_error("Arguments is a directory"));
        case S_IXUSR: throw(std::runtime_error("Argument is binary"));
    }
    std::ifstream fs(databasePath.c_str());//ouvertur du ifstream ici pas besoin de plus 
    if (!fs.is_open())
        throw (std::runtime_error("Error Database"));

    std::string line;
    while (std::getline(fs, line)) {
        //verifier que le format date | value est repecté
        std::istringstream iss(line);
        
        
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
