/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:42:25 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/18 19:30:32 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cctype>

void to_char(std::string to_convert)
{
	try 
	{
        if (to_convert.length() == 1 && !std::isdigit(to_convert[0]))
		{
            std::cout << "'" << to_convert[0] << "'" << std::endl;
        } 
		else 
		{
            int as_int = static_cast<int>(std::strtol(to_convert.c_str(), NULL, 10));
            if (as_int >= std::numeric_limits<char>::min() && as_int <= std::numeric_limits<char>::max())
			{
                char as_char = static_cast<char>(as_int);
                if (std::isprint(as_char))
				{
                    std::cout << "'" << as_char << "'" << std::endl;
                } 
				else
				{
                    std::cout << "Non displayable" << std::endl;
                }
            }
			else 
			{
                std::cout << "impossible" << std::endl;
            }
        }
    }
	catch (...) 
	{
        std::cout << "impossible" << std::endl;
    }	
}

ScalarConverter::ScalarConverter()
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	(void) src;
	return (*this);
} 

ScalarConverter::~ScalarConverter()
{
	return ;
}

bool ScalarConverter::handle_special_case(const std::string &to_convert)
{
	return (to_convert == "-inf" || to_convert == "+inf" || to_convert == "nan" || to_convert == "-inff" || to_convert == "+inff" || to_convert == "nanf");
}

void ScalarConverter::convert(std::string const &to_convert)
{
	if (to_convert.empty())
	{
		std::cerr << "Error, string is empty" << std::endl;
		return ;
	}
	if (ScalarConverter::handle_special_case(to_convert))
	{
		if (to_convert[to_convert.size() - 1]== 'f')
		{
			std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << to_convert << std::endl;
            std::cout << "double: " << to_convert.substr(0, to_convert.size() - 1);
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << to_convert + "f" << std::endl;
            std::cout << "double: " << to_convert << std::endl;
		}
		return ;
	}
	std::cout << "char: ";
	to_char(to_convert);
	std::cout << std::endl;

	/* std::cout << "char: ";
	convert_tester<char>(to_convert) ? std::cout << static_cast<char>(to_convert) : throw ScalarConverter::ConversionError();
	std::cout <<std::endl;
	std::cout << "int: ";
	convert_tester<int>(to_convert) ? std::cout << static_cast<int>(to_convert) : throw ScalarConverter::ConversionError();
	std::cout <<std::endl;
	std::cout << "float: ";
	convert_tester<float>(to_convert) ? std::cout << static_cast<float>(to_convert) : throw ScalarConverter::ConversionError();
	std::cout <<std::endl;
	std::cout << "double: ";
	convert_tester<double>(to_convert) ? std::cout << static_cast<double>(to_convert) : throw ScalarConverter::ConversionError();
	std::cout <<std::endl; */
}

const char *ScalarConverter::ConversionError::what(void) const throw()
{
	return ("Error, conversion failled");
}