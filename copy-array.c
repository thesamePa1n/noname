#include <stdio.h>
#define N 5

int main() {
  int arr[N] = {0};

  printf("Оригинальный массив: ");
  for (int i = 0; i < N; i++) {
    int num;
    scanf("%d", &num);
    arr[i] = num;
  }

  int arr_copy[N];

  for (int i = 0; i < N; i++) {
    arr_copy[i] = arr[N - i - 1];
  }

  printf("\nСкопированный массив: ");
  for (int i = 0; i < N; i++) {
    printf("%d ", arr_copy[i]);
  }
  
  return 0;
}