#pragma once

#include <cmath>
#include <iostream>

#ifndef __INT_MIN__
#define __INT_MIN__ -2147483648
#endif

#ifndef __INT_MAX_FLOAT__
#define __INT_MAX_FLOAT__ 2147483647.0f
#endif

#ifndef __INT_MIN_FLOAT__
#define __INT_MIN_FLOAT__ -2147483648.0f
#endif

class Fixed {
 private:
  int _value;
  static const int _fractionalBits = 8;

 public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  ~Fixed();

  Fixed(const int intValue);
  Fixed(const float floatValue);

  int getRawBits() const;
  void setRawBits(int const raw);
  float toFloat() const;
  int toInt() const;

  bool operator>(const Fixed& other) const;
  bool operator<(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;

  Fixed operator+(const Fixed& other) const;
  Fixed operator-(const Fixed& other) const;
  Fixed operator*(const Fixed& other) const;
  Fixed operator/(const Fixed& other) const;

  Fixed& operator++();    // ++Fixed
  Fixed operator++(int);  // Fixed++
  Fixed& operator--();    // --Fixed
  Fixed operator--(int);  // Fixed--

  static Fixed& min(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);
  static Fixed& max(Fixed& a, Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
