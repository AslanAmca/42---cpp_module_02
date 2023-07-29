/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:37:21 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/29 19:42:26 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	fixedPointNumberValue = 0;
}

Fixed::Fixed(const int integer)
{
	fixedPointNumberValue = integer << fractionalBits;
}

Fixed::Fixed(const float floatingPoint)
{
	fixedPointNumberValue = roundf(floatingPoint * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		fixedPointNumberValue = other.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
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

/*--------------- Comparison Operators ---------------*/

bool Fixed::operator>(const Fixed &other) const
{
	return toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed &other) const
{
	return toFloat() < other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) const
{
	return toFloat() >= other.toFloat();
}

bool Fixed::operator<=(const Fixed &other) const
{
	return toFloat() <= other.toFloat();
}

bool Fixed::operator==(const Fixed &other) const
{
	return toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed &other) const
{
	return toFloat() != other.toFloat();
}

/*--------------- Arithmetic Operators ---------------*/

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(toFloat() / other.toFloat());
}

/*--------------- Pre-increment & Pre-decrement ---------------*/

Fixed &Fixed::operator++(void)
{
	fixedPointNumberValue++;
	return *this;
}

Fixed &Fixed::operator--(void)
{
	fixedPointNumberValue--;
	return *this;
}

/*--------------- Post-increment & Post-decrement ---------------*/

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	fixedPointNumberValue++;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	fixedPointNumberValue--;
	return temp;
}

/*--------------- Min & Max ---------------*/

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a.toFloat() < b.toFloat() ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a.toFloat() > b.toFloat() ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a.toFloat() < b.toFloat() ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a.toFloat() > b.toFloat() ? a : b;
}

/*--------------- Overload Output Stream ---------------*/

std::ostream &operator<<(std::ostream &output, const Fixed &other)
{
	output << other.toFloat();
	return output;
}
