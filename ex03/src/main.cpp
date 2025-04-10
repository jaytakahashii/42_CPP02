#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void test(Point a, Point b, Point c, Point p) {
  if (bsp(a, b, c, p)) {
    std::cout << YELLOW "\nPoint (" << p.getX() << ", " << p.getY() << ") is ";
    std::cout << "inside";
  } else {
    std::cout << GREEN "\nPoint (" << p.getX() << ", " << p.getY() << ") is ";
    std::cout << "outside";
  }
  std::cout << " the triangle.\n" RESET << std::endl;
}

int main() {
  Point a(0, 0);
  Point b(10, 0);
  Point c(5, 10);

  Point p1(5, 5);    // inside
  Point p2(0, 0);    // apex -> outside
  Point p3(10, 0);   // apex -> outside
  Point p4(5, 10);   // apex -> outside
  Point p5(5, 2.5);  // inside
  Point p6(5, 0);    // on the edge -> outside

  test(a, b, c, p1);
  test(a, b, c, p2);
  test(a, b, c, p3);
  test(a, b, c, p4);
  test(a, b, c, p5);
  test(a, b, c, p6);

  return 0;
}
