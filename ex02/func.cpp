/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuture <phuture@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:20:35 by phuture           #+#    #+#             */
/*   Updated: 2025/01/20 15:37:53 by phuture          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
    srand(static_cast<unsigned>(time(0)));
    int rando = rand() % 3;

    if (rando == 0)
        return (new A());
    else if (rando == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Type A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Type B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Type C" << std::endl;
    else
        std::cout << "Unknow type..." << std::endl; 
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast &)
    {
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
    }
    catch (std::bad_cast &)
    {
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    }
    catch (std::bad_cast &)
    {
    }
}