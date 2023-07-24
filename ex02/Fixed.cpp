/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:37:21 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/24 21:52:41 by aaslan           ###   ########.fr       */
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

/*--------------- Karşılaştırma Operatörleri ---------------*/

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

/*--------------- Aritmetik Operatörler ---------------*/

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(toFloat() * other.toFloat());
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
