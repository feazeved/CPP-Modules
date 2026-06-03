
#include "Point.hpp"
#include <cmath>

static float	calculate_area(Point a, Point b, Point c)
{
	float	x0;
	float	x1;
	float	x2;
	float	y0;
	float	y1;
	float	y2;
	float	result;

	x0 = a.getX().toFloat();
	x1 = b.getX().toFloat();
	x2 = c.getX().toFloat();
	y0 = a.getY().toFloat();
	y1 = b.getY().toFloat();
	y2 = c.getY().toFloat();

	result = (x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1)) / 2;
	return (fabsf(result));
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
	const float	area1 = calculate_area(a, b, point);
	const float	area2 = calculate_area(a, c, point);
	const float	area3 = calculate_area(c, b, point);
	const float	total_area = calculate_area(a, b, c);

	if (!area1 || !area2 || !area3)
		return (false);
	else if (fabsf((area1 + area2 + area3) - total_area) < 1e-4f)
		return (true);
    return (false);
}
