#include "Fixed.hpp"

#include <cmath>

// === Orthodox Canonical Form ===
Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const Fixed& other) {
  *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    _value = other._value;
  }
  return *this;
}

Fixed::~Fixed() {
}

// === constructor(int, float) ===
Fixed::Fixed(const int intValue) {
  _value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
  _value = roundf(floatValue * (1 << _fractionalBits));
}

// === member functions ===
int Fixed::getRawBits() const {
  return _value;
}

void Fixed::setRawBits(int const raw) {
  _value = raw;
}

float Fixed::toFloat() const {
  return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
  return _value >> _fractionalBits;
}

// === difference operators ===
bool Fixed::operator>(const Fixed& other) const {
  return _value > other._value;
}
bool Fixed::operator<(const Fixed& other) const {
  return _value < other._value;
}
bool Fixed::operator>=(const Fixed& other) const {
  return _value >= other._value;
}
bool Fixed::operator<=(const Fixed& other) const {
  return _value <= other._value;
}
bool Fixed::operator==(const Fixed& other) const {
  return _value == other._value;
}
bool Fixed::operator!=(const Fixed& other) const {
  return _value != other._value;
}

// === arithmetic operators ===
Fixed Fixed::operator+(const Fixed& other) const {
  Fixed result;
  result.setRawBits(_value + other._value);
  return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
  Fixed result;
  result.setRawBits(_value - other._value);
  return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
  Fixed result;
  long long mul = static_cast<long long>(_value) * other._value;
  result.setRawBits(static_cast<int>(mul >> _fractionalBits));
  return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
  Fixed result;
  long long div =
      (static_cast<long long>(_value) << _fractionalBits) / other._value;
  result.setRawBits(static_cast<int>(div));
  return result;
}

// === increment and decrement operators ===
Fixed& Fixed::operator++() {
  _value += 1;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  ++(*this);
  return temp;
}

Fixed& Fixed::operator--() {
  _value -= 1;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp = *this;
  --(*this);
  return temp;
}

// === static member functions ===
Fixed& Fixed::min(Fixed& a, Fixed& b) {
  return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
  return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  return (a > b) ? a : b;
}

// === output operator ===
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}
