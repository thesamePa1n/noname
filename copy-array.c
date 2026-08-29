#include <stdio.h>
#define N 6

int main() {
  int arr[N] = {0};

  for (int i = 0; i < N; i++) {
    int num;
    scanf("%d", &num);
    arr[i] = num;
  }

  for (int i = 0; i < N / 2; i++) {
    int tmp = arr[i];
    arr[i] = arr[N - i - 1];
    arr[N - i - 1] = tmp;
  }

  for (int i = 0; i < N; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}