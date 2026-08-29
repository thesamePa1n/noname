#include <stdio.h>
#define N 6

int main() {
  int arr[N] = {0};

  for (int i = 0; i < N; i++) {
    int num;
    scanf("%d", &num);
    arr[i] = num;
  }

  int tmp = arr[0];
  for (int i = 0; i < N - 1; i++) {
    arr[i] = arr[i + 1];
  }
  arr[N - 1] = tmp;

  for (int i = 0; i < N; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}

// 1 2 3 4 5 -> 2 3 4 5 1