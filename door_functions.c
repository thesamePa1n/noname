#include <stdio.h>
#include <math.h>

double anez(double x) {
  return 1 / (1 + x*x);
}

double lemniscate(double x) {
  return sqrt(sqrt(1 + 4 * x*x) - x*x - 1);
}

double hyperbola(double x) {
  return 1 / (x*x);
}

int main() {
  double pi = 3.14159265358979323846;
  double x;
  double step = 2.0 * pi / 41.0;

  for (int i = 0; i < 42; i++) {
        x = -pi + i * step;

        printf("%.7f|", x);
        printf("%.7f|", anez(x));

        if (x >= -sqrt(2.0) && x <= sqrt(2.0))
            printf("%.7f|", lemniscate(x));
        else
            printf("-|");

        if (x == 0.0)
            printf("-");
        else
            printf("%.7f", hyperbola(x));

        printf("\n");
    } 

  return 0;
}