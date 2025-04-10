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
