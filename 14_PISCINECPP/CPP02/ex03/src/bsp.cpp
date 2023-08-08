/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:40:26 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/28 11:17:46 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Point.hpp"

bool Point::bsp(const Point& a, const Point& b, const Point& c, const Point& point) {

    if ((point.getX() == a.getX() && point.getY() == a.getY())
        || (point.getX() == b.getX() && point.getY() == b.getY())
        || (point.getX() == c.getX() && point.getY() == c.getY()))
        return (true);

    /*
        si a_x est < à b_x alors on verifie si a_x est < à c_x
            si c'est le cas alors la valeur minimal est a_x sinon c'est c_x
        sinon si a_x > a b_x alors on va comparer qui de b_x et de c_x est inférieur
            dès lors on choisir le minimum entre b_x et c_x.
        etc..
    */
    float minX = a.getX() < b.getX() ? (a.getX() < c.getX() ? a.getX() : c.getX()) : (b.getX() < c.getX() ? b.getX() : c.getX());
    float maxX = a.getX() > b.getX() ? (a.getX() > c.getX() ? a.getX() : c.getX()) : (b.getX() > c.getX() ? b.getX() : c.getX());
    float minY = a.getY() < b.getY() ? (a.getY() < c.getY() ? a.getY() : c.getY()) : (b.getY() < c.getY() ? b.getY() : c.getY());
    float maxY = a.getY() > b.getY() ? (a.getY() > c.getY() ? a.getY() : c.getY()) : (b.getY() > c.getY() ? b.getY() : c.getY());

    if (point.getX() < minX || point.getX() > maxX || point.getY() < minY || point.getY() > maxY)
        return false;
    else
        return true;
}

