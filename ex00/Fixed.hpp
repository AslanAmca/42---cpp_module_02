/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:56:16 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/29 19:17:16 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int fixedPointNumberValue;
	static const int fractionalBits = 8;

public:
	Fixed(void);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
