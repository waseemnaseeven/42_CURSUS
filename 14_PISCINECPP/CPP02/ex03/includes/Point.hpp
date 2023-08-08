/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:14:24 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/28 11:18:34 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

	public:
		Point();
		Point(const float x, const float y);
		Point(Point const &src);
		~Point();

		float	getX() const;
		float	getY() const;

		Point& operator=(const Point& src);
		Point operator-(const Point &src) const;
		float cross(const Point& src) const ;

    	bool bsp(const Point& a, const Point& b, const Point& c, const Point& point);

	private:
		float _x;
		float _y;

};

#endif
