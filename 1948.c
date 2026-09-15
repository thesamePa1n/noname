#include <stdio.h>

int find_max_prime(int n) {
  if (n < 0) {
    n = -n;
  }
  int d = 2;
  int max_prime = 2;

  while (n > 1) {
    int temp = n; 
    while (temp >= d) { 
      temp -= d;
    }
    if (temp == 0) {
      max_prime = d;
      int next_n = 0;
      while (n >= d) { 
        n -= d;
        next_n += 1;
      }
      n = next_n;
    }
    else {
      d += 1;
    }
  }

  return max_prime;
}

int main() {
  int a;
  if (scanf("%d", &a) != 1) {
    printf("n/a");
    return 0;
  }

  int next_char = getchar();

  while (next_char != '\n' && next_char != EOF) {
    if (next_char != ' ' && next_char != '\t') {
      printf("n/a");
      return 0;
    }
    next_char = getchar();
  }

  if (a == 0 || a == 1 || a == -1) {
    printf("n/a");
    return 0;
  }
  printf("%d", find_max_prime(a));

  return 0;
}