/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:37:21 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/29 19:19:38 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;

	fixedPointNumberValue = 0;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;

	fixedPointNumberValue = integer << fractionalBits;
}

Fixed::Fixed(const float floatingPoint)
{
	std::cout << "Float constructor called" << std::endl;

	fixedPointNumberValue = roundf(floatingPoint * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

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
	return fixedPointNumberValue;
}

void Fixed::setRawBits(int const raw)
{
	fixedPointNumberValue = raw;
}

float Fixed::toFloat(void) const
{
	return (float)fixedPointNumberValue / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return fixedPointNumberValue >> fractionalBits;
}

std::ostream &operator<<(std::ostream &output, const Fixed &other)
{
	output << other.toFloat();
	return output;
}
