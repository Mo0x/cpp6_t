/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:53:54 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/18 19:31:12 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &src);
	ScalarConverter &operator=(ScalarConverter const &src);
	~ScalarConverter();

	public:
	static bool handle_special_case(const std::string &to_convert);
	static void convert(std::string const &to_convert);
	class ConversionError : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

#endif
