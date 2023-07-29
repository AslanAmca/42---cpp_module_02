/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:56:16 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/29 19:26:54 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int fixedPointNumberValue;
	static const int fractionalBits = 8;

public:
	Fixed(void);
	Fixed(const int integer);
	Fixed(const float floatingPoint);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &operator++(void);
	Fixed &operator--(void);

	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &output, const Fixed &other);

#endif
