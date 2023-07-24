/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:56:16 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/22 12:33:25 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	// sayının tam sayı (int) kısmı.
	int fixedPointNumberValue;

	// sayının ondalık kısmının kaç bitle temsil edileceği, hassasiyet.
	// binary point sonrasında (ondalık kısım) 8 bit olacak.
	static const int fractionalBits = 8;

public:
	// default constructor
	Fixed(void);

	// int değeri fixed-point number'a dönüştürür.
	Fixed(const int integer);

	// float değeri fixed-point number'a dönüştürür.
	Fixed(const float floatingPoint);

	// copy constructor
	// Fixed x(y); ifadesi ile değerleri kopyalamayı sağlayacak.
	Fixed(const Fixed &other);

	// copy assignment operator overload (= operator)
	// x = y; ifadesi ile değerleri kopyamalayı sağlayacak.
	Fixed &operator=(const Fixed &other);

	// destructor
	~Fixed(void);

	// fixed-point value değerini dönecek.
	int getRawBits(void) const;

	// fixed-point value değerini belirleyecek.
	void setRawBits(int const raw);

	// fixed-point number'ı float değere dönüştürür.
	float toFloat(void) const;

	// fixed-point number'ı int değere dönüştürür.
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &output, const Fixed &other);

#endif
