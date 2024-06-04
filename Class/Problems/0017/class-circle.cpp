#include <iostream>
using namespace std;

class Circle {
  private:
    const double pi = 3.14159;

    int r;

  public:
    Circle(int r) { this->r = r; }

    double diameter() { return 2 * r; }
    double circumference() { return 2 * pi * r; }
    double area() { return pi * r * r; }
};

int main() {
    int r;
    scanf("%d", &r);

    Circle circle(r);
    printf("%g\n", circle.diameter());
    printf("%g\n", circle.circumference());
    printf("%g\n", circle.area());

    return 0;
}
