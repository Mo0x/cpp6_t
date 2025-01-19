/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Serializer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuture <phuture@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:43:44 by phuture           #+#    #+#             */
/*   Updated: 2025/01/19 16:59:05 by phuture          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef     struct Data
{
    std::string a;
    long b;
    double c;
}   Data;

class Serializer
{
    private:
    Serializer();
    Serializer(Serializer const &src);
    Serializer &operator=(Serializer const &src);
    ~Serializer();

    public:
    static uintptr_t serialize(Data *ptr);
    Data *deserialize(uintptr_t raw);
};

#endif
