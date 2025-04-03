#include "Point.hpp"

// === Orthodox Canonical Form ===
Point::Point() : _x(0), _y(0) {
}

Point::Point(const float xValue, const float yValue) : _x(xValue), _y(yValue) {
}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {
}

Point& Point::operator=(const Point& other) {
  (void)other;
  return *this;
}

Point::~Point() {
}

Fixed Point::getX() const {
  return _x;
}
Fixed Point::getY() const {
  return _y;
}
