#pragma once

#include <cmath>
#include <iostream>

class Fixed {
 private:
  int _value;
  static const int _fractionalBits = 8;

 public:
  Fixed();
  Fixed(const int intValue);      // constructor with int
  Fixed(const float floatValue);  // constructor with float
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  ~Fixed();

  int getRawBits() const;
  void setRawBits(int const raw);

  float toFloat() const;
  int toInt() const;
};

// comparison operators
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
