#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class   Point {
public:
    Point();
    Point(const Fixed& x, const Fixed& y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point();

    Fixed   getX();
    Fixed   getY();


private:
    const Fixed x;
    const Fixed y;

};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif
