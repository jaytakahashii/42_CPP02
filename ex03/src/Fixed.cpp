#include "Fixed.hpp"

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
  std::cout << "Int constructor called" << std::endl;
  if (intValue > (__INT_MAX__ >> _fractionalBits) ||
      intValue < (__INT_MIN__ >> _fractionalBits)) {
    throw std::overflow_error(RED "Overflow error" RESET);
  }
  _value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
  std::cout << "Float constructor called" << std::endl;
  double scaled =
      roundf(static_cast<double>(floatValue) * (1 << _fractionalBits));
  if (scaled > __INT_MAX_FLOAT__ || scaled < __INT_MIN_FLOAT__) {
    throw std::overflow_error(RED "Overflow error" RESET);
  }
  _value = static_cast<int>(scaled);
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
  if (_value + other._value > (__INT_MAX__ >> _fractionalBits) ||
      _value + other._value < (__INT_MIN__ >> _fractionalBits)) {
    throw std::overflow_error(RED "Overflow error" RESET);
  }
  result.setRawBits(_value + other._value);
  return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
  Fixed result;
  if (_value - other._value > (__INT_MAX__ >> _fractionalBits) ||
      _value - other._value < (__INT_MIN__ >> _fractionalBits)) {
    throw std::overflow_error(RED "Overflow error" RESET);
  }
  result.setRawBits(_value - other._value);
  return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
  Fixed result;
  if (_value * other._value > (__INT_MAX__ >> _fractionalBits) ||
      _value * other._value < (__INT_MIN__ >> _fractionalBits)) {
    throw std::overflow_error(RED "Overflow error" RESET);
  }
  int mul = _value * other._value;
  result.setRawBits(mul >> _fractionalBits);
  return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
  Fixed result;
  if (other._value == 0) {
    throw std::invalid_argument(RED "Division by zero" RESET);
  }
  if (_value << _fractionalBits > (__INT_MAX__ >> _fractionalBits) ||
      _value << _fractionalBits < (__INT_MIN__ >> _fractionalBits)) {
    throw std::overflow_error(RED "Overflow error" RESET);
  }
  result.setRawBits((_value << _fractionalBits) / other._value);
  return result;
}

// === increment and decrement operators ===
Fixed& Fixed::operator++() {
  if (_value + 1 > (__INT_MAX__ >> _fractionalBits)) {
    throw std::overflow_error(RED "Overflow error" RESET);
  }
  _value += 1;
  return *this;
}

Fixed Fixed::operator++(int) {
  if (_value + 1 > (__INT_MAX__ >> _fractionalBits)) {
    throw std::overflow_error(RED "Overflow error" RESET);
  }
  Fixed temp = *this;
  ++(*this);
  return temp;
}

Fixed& Fixed::operator--() {
  if (_value - 1 < (__INT_MIN__ >> _fractionalBits)) {
    throw std::overflow_error(RED "Overflow error" RESET);
  }
  _value -= 1;
  return *this;
}

Fixed Fixed::operator--(int) {
  if (_value - 1 < (__INT_MIN__ >> _fractionalBits)) {
    throw std::overflow_error(RED "Overflow error" RESET);
  }
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

// === abs() ===
Fixed Fixed::abs() const {
  Fixed result;
  if (_value < 0 && _value > (__INT_MIN__ >> _fractionalBits)) {
    throw std::overflow_error(RED "Overflow error" RESET);
  }
  result.setRawBits(_value < 0 ? -_value : _value);
  return result;
}

// === output operator ===
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}
