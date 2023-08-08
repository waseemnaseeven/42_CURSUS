/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:42:03 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/28 11:16:09 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Point.hpp"

int main( void ) {

	Point a(0,0);
	Point b(3,0);
	Point c(0,3);

	Point p1(1,1);
	bool res1 = p1.bsp(a,b,c,p1);

	Point p2(2,2);
	bool res2 = p2.bsp(a,b,c,p2);

	Point p3(4,4);
	bool res3 = p3.bsp(a,b,c,p3);

	Point p4(1,0);
	bool res4 = p4.bsp(a,b,c,p4);

	Point p5(3,0);
	bool res5 = p5.bsp(a,b,c,p5);

	Point p6(0,3);
	bool res6 = p6.bsp(a,b,c,p6);

	Point p7(3,3);
	bool res7 = p7.bsp(a,b,c,p7);

	Point p8(-1,-1);
	bool res8 = p8.bsp(a,b,c,p8);

	std::cout << "Res 1: " << (res1 ? "true" : "false") << std::endl;
  	std::cout << "Res 2: " << (res2 ? "true" : "false") << std::endl;
  	std::cout << "Res 3: " << (res3 ? "true" : "false") << std::endl;
  	std::cout << "Res 4: " << (res4 ? "true" : "false") << std::endl;
	std::cout << "Res 5: " << (res5 ? "true" : "false") << std::endl;
	std::cout << "Res 6: " << (res6 ? "true" : "false") << std::endl;
	std::cout << "Res 7: " << (res7 ? "true" : "false") << std::endl;
	std::cout << "Res 8: " << (res8 ? "true" : "false") << std::endl;

	return 0;
}
