/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:11:08 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/12/21 19:52:57 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"


BitcoinExchange:: BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange & src) {
    *this = src;
}

BitcoinExchange::~ BitcoinExchange()
{
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange & rhv) {
    if (this != &rhv) {
        _rate = rhv._rate;
    }
    return *this;
}

//premiere etape on va parser la base de données passée en argument
//on doit pouvoir l'ouvrir, c'st ni un dossier ni un binaire 

/**********************************************************************************
 *                          Exception
***********************************************************************************/

const char* BitcoinExchange::NotGoodDatabase::what() const throw() {
    return ("Not good database");
}
