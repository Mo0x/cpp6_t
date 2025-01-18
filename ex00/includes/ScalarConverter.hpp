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

	public:
	static void convert(std::string const &to_convert);
	class ConversionError : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

template<typename T>
bool convert_tester(std::string const &to_convert)
{
	std::istringstream is(to_convert);
	T test;
	is >> test;
	bool const conversion_success = !is.fail();
	bool const full_string_used = is.rdbuf()->in_avail() == 0;
	return conversion_success && full_string_used;
}

#endif
