/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:58:29 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/25 00:03:34 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
}

Point::Point(const float a, const float b) : x(a), y(b)
{
}

Point::Point(const Point &other)
{
	*this = other;
}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		const_cast<Fixed&>(x) = other.x;
		const_cast<Fixed&>(y) = other.y;
	}
	return *this;
}

Point::~Point(void)
{
}

Fixed Point::getX(void) const
{
	return x;
}

Fixed Point::getY(void) const
{
	return y;
}
