#include <iostream>

#include "Fixed.hpp"
#include "color.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << BLUE "Initial values:\n" RESET;
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;

  std::cout << BLUE "\nIncrement / Decrement:\n" RESET;
  std::cout << "++a: " << ++a << std::endl;
  std::cout << "a:   " << a << std::endl;
  std::cout << "a++: " << a++ << std::endl;
  std::cout << "a:   " << a << std::endl;
  std::cout << "--a: " << --a << std::endl;
  std::cout << "a:   " << a << std::endl;
  std::cout << "a--: " << a-- << std::endl;
  std::cout << "a:   " << a << std::endl;

  std::cout << BLUE "\nArithmetic Operators:\n" RESET;
  Fixed x(3.5f);
  Fixed y(1.25f);
  std::cout << "x: " << x << ", y: " << y << std::endl;
  std::cout << "x + y = " << (x + y) << std::endl;
  std::cout << "x - y = " << (x - y) << std::endl;
  std::cout << "x * y = " << (x * y) << std::endl;
  std::cout << "x / y = " << (x / y) << std::endl;

  std::cout << BLUE "\nComparison Operators:\n" RESET;
  std::cout << "x: " << x << ", y: " << y << std::endl;
  std::cout << "x > y:  " << (x > y) << std::endl;
  std::cout << "x < y:  " << (x < y) << std::endl;
  std::cout << "x >= y: " << (x >= y) << std::endl;
  std::cout << "x <= y: " << (x <= y) << std::endl;
  std::cout << "x == y: " << (x == y) << std::endl;
  std::cout << "x != y: " << (x != y) << std::endl;

  std::cout << BLUE "\nMin / Max:\n" RESET;
  Fixed c(10);
  Fixed d(42);
  std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
  std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;
  const Fixed e(3.14f);
  const Fixed f(2.71f);
  std::cout << "min(e, f): " << Fixed::min(e, f) << std::endl;
  std::cout << "max(e, f): " << Fixed::max(e, f) << std::endl;

  return 0;
}
