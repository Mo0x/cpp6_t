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
#include <sstream>
#include <iostream>
#include <vector>



void ScalarConverter::convert(std::string const &to_convert)
{
	if (to_convert.empty())
	{
		std::cerr << "Error, string is empty" << std::endl;
		return ;
	}
	std::cout << "char: ";
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
	std::cout <<std::endl;
}

const char *ScalarConverter::ConversionError::what(void) const throw()
{
	return ("Error, conversion failled");
}