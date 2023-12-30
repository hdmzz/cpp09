/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:07:26 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/12/22 20:01:49 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <ctime>
# include <map>
# include <sys/stat.h>
# include <algorithm>
# include <string>

class  BitcoinExchange
{
private:
    std::map<time_t, double> _rate;
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange & src);
    ~BitcoinExchange();
    
    BitcoinExchange & operator=(BitcoinExchange & rhv);


    class NotGoodDatabase : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

#endif
