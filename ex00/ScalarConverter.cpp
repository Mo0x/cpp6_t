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
#include <cerrno>
#include <climits>

void to_char(std::string const &to_convert)
{
	try
	{
		if (to_convert.length() == 1 && !std::isdigit(to_convert[0]))
		{
			std::cout << "'" << to_convert[0] << "'" << std::endl;
   		} 
    	else 
    	{
       		char *endptr;
	        long as_int = std::strtol(to_convert.c_str(), &endptr, 10);

        	if (*endptr != '\0') 
        	{
         	   throw ScalarConverter::ConversionError();
        	}
        	if (as_int < CHAR_MIN || as_int > CHAR_MAX) 
       		{
         	   throw ScalarConverter::ConversionError();
        	}
        	char as_char = static_cast<char>(as_int);
        	if (std::isprint(as_char)) 
        	{
         	   std::cout << "'" << as_char << "'" << std::endl;
        	} 
       		else 
    		{
    			std::cout << "Non displayable." << std::endl;
			}
	    }
    }
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	
}

static void to_int(std::string const &to_convert)
{
	try
	{
        char *endptr;
        long as_long = std::strtol(to_convert.c_str(), &endptr, 10);

        if (*endptr != '\0')
		{
            throw ScalarConverter::ConversionError();
        }
        if (as_long > INT_MAX || as_long < INT_MIN) 
		{
            throw ScalarConverter::ConversionError();
        }
		else 
		{
            std::cout << static_cast<int>(as_long) << std::endl;
        }
    }
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

static void to_float(std::string const &to_convert)
{
	 try
	 {
        float as_float = std::strtof(to_convert.c_str(), NULL);
        if (errno == ERANGE)
		{
            throw ScalarConverter::ConversionError();
        } 
		else 
		{
            std::cout << as_float << "f" << std::endl;
        }
    }
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

static void to_double(std::string const &to_convert)
{
	try
	{
		double as_double = std::strtod(to_convert.c_str(), NULL);
		if (errno == ERANGE)
		{
			throw ScalarConverter::ConversionError();
		}
		else
		{
			std::cout << as_double << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
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
	std::cout << "int: ";
	to_int(to_convert);
	std::cout << "float: ";
	to_float(to_convert);
	std::cout << "double: ";	
	to_double(to_convert);
}

const char *ScalarConverter::ConversionError::what(void) const throw()
{
	return ("Error, conversion failled: impossible.");
}