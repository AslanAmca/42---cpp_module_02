/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:07:25 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/25 16:50:09 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Üçgenin alanını hesaplamak için yardımcı bir fonksiyon
static Fixed triangleArea(Point const a, Point const b, Point const c)
{
	// Alan = | (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2 |
	Fixed A = a.getX() * (b.getY() - c.getY());
	Fixed B = b.getX() * (c.getY() - a.getY());
	Fixed C = c.getX() * (a.getY() - b.getY());
	Fixed area = (A + B + C) / Fixed(2.0f);

	if (area < 0)
		area = area * Fixed(-1.0f);

	return area;
}

// Bir noktanın üçgenin içinde olup olmadığını kontrol eden fonksiyon
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Üçgenin alanını hesapla
	Fixed abcArea = triangleArea(a, b, c);

	// Nokta ile üçgenin köşeleri arasındaki alanları hesapla
	Fixed pabArea = triangleArea(a, b, point);
	Fixed pbcArea = triangleArea(point, b, c);
	Fixed pcaArea = triangleArea(a, point, c);

	// Nokta kenarda veya köşedeyse, false döndür
	if (abcArea == 0 || pabArea == 0 || pbcArea == 0 || pcaArea == 0)
		return false;

	// Eğer nokta üçgenin içindeyse, üçgenin alanı ile üç küçük üçgenin toplam alanı eşit olmalıdır.
	return abcArea == (pabArea + pbcArea + pcaArea);
}
