#include "Point.hpp"

Fixed area(Point const a, Point const b, Point const c) {
  return Fixed(0.5f) *
         Fixed(
             (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) +
             (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) +
             (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())))
             .abs();
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed S_ABC = area(a, b, c);
  Fixed S_ABP = area(a, b, point);
  Fixed S_BCP = area(b, c, point);
  Fixed S_CAP = area(c, a, point);

  return (S_ABC == (S_ABP + S_BCP + S_CAP)) && (S_ABP != Fixed(0)) &&
         (S_BCP != Fixed(0)) && (S_CAP != Fixed(0));
}
