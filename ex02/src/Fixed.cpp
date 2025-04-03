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
    this->_value = other._value;
  }
  return *this;
}

Fixed::~Fixed() {
}

// === constructor(int, float) ===
Fixed::Fixed(const int intValue) {
  this->_value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
  this->_value = roundf(floatValue * (1 << _fractionalBits));
}

// === member functions ===
int Fixed::getRawBits() const {
  return this->_value;
}

void Fixed::setRawBits(int const raw) {
  this->_value = raw;
}

float Fixed::toFloat() const {
  return static_cast<float>(this->_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
  return this->_value >> _fractionalBits;
}

// === difference operators ===
bool Fixed::operator>(const Fixed& other) const {
  return this->_value > other._value;
}
bool Fixed::operator<(const Fixed& other) const {
  return this->_value < other._value;
}
bool Fixed::operator>=(const Fixed& other) const {
  return this->_value >= other._value;
}
bool Fixed::operator<=(const Fixed& other) const {
  return this->_value <= other._value;
}
bool Fixed::operator==(const Fixed& other) const {
  return this->_value == other._value;
}
bool Fixed::operator!=(const Fixed& other) const {
  return this->_value != other._value;
}

// === arithmetic operators ===
Fixed Fixed::operator+(const Fixed& other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
  if (other._value == 0) {
    std::cerr << "Error: Division by zero" << std::endl;
    return Fixed();
  }
  return Fixed(this->toFloat() / other.toFloat());
}

// === increment and decrement operators ===
Fixed& Fixed::operator++() {
  this->_value += 1;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  ++(*this);
  return temp;
}

Fixed& Fixed::operator--() {
  this->_value -= 1;
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
