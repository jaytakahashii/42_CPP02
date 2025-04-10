#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
  std::cout << "Int constructor called" << std::endl;
  if (intValue > (__INT_MAX__ >> _fractionalBits) ||
      intValue < (__INT_MIN__ >> _fractionalBits)) {
    throw std::overflow_error("Overflow error");
  }
  _value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
  std::cout << "Float constructor called" << std::endl;
  double scaled =
      roundf(static_cast<double>(floatValue) * (1 << _fractionalBits));
  if (scaled > __INT_MAX_FLOAT__ || scaled < __INT_MIN_FLOAT__) {
    throw std::overflow_error("Overflow error");
  }
  _value = static_cast<int>(scaled);
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    _value = other._value;
  }
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat() const {
  return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
  return _value >> _fractionalBits;
}

int Fixed::getRawBits() const {
  return _value;
}

void Fixed::setRawBits(int const raw) {
  _value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
  out << fixed.toFloat();
  return out;
}
