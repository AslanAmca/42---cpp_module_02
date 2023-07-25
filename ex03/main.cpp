/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:35:40 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/25 16:49:30 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point a(0, 0);
    Point b(4, 6);
    Point c(8, 0);
    Point point1(4, 3);
    Point point2(7, 5);
    Point point3(0, 2);

    std::cout << "Example:" << std::endl;
    std::cout << "Input: " << std::endl;
    std::cout << "A = (0, 0), B = (4, 6), C = (8, 0)" << std::endl;
    std::cout << "P1 = (4, 3), P2 = (7, 5), P3 = (0, 2)" << std::endl;
    std::cout << "Overview:" << std::endl;
    std::cout << "                   P2" << std::endl;
    std::cout << "            B(4,6)	" << std::endl;
    std::cout << "              / \\	" << std::endl;
    std::cout << "             /   \\	" << std::endl;
    std::cout << "            /  P1 \\	" << std::endl;
    std::cout << "        P3 /       \\	" << std::endl;
    std::cout << "          /         \\" << std::endl;
    std::cout << "  A(0,0) ------------ C(8,0)" << std::endl;
    std::cout << std::endl;
    std::cout << "Point1 inside Triangle: " << (bsp(a, b, c, point1) ? "TRUE" : "FALSE");
    std::cout << std::endl;
    std::cout << "Point2 inside Triangle: " << (bsp(a, b, c, point2) ? "TRUE" : "FALSE");
    std::cout << std::endl;
    std::cout << "Point3 inside Triangle: " << (bsp(a, b, c, point3) ? "TRUE" : "FALSE");
    std::cout << std::endl;
}
