/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:37:21 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/21 14:38:41 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;

	fixedPointNumberValue = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;

	// this pointer'ını Dereference ederek mevcut class'a ulaşıyoruz.
	// = other ile aşağıda overload yaptığımız operator olayını tetikliyoruz.
	// pdf'te ki çıktı için bunu yapıyoruz ama normalde doğru yöntem bu değil.
	// değişkenleri tek tek atamak çok daha doğru bir yöntem.
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	// verilen nesne kendisi değilse atamayı yap
	if (this != &other)
		fixedPointNumberValue = other.getRawBits();

	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return fixedPointNumberValue;
}

void Fixed::setRawBits(int const raw)
{
	fixedPointNumberValue = raw;
}
