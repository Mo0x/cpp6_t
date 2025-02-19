/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuture <phuture@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:03:55 by phuture           #+#    #+#             */
/*   Updated: 2025/01/20 15:36:10 by phuture          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "func.hpp"

int main(void)
{
    Base *base = generate();
    std::cout << "Identify via pointer: ";
    identify(base);
    std::cout << "Identify via ref: ";
    delete base;
    return 0;
}