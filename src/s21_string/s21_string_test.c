#include <stdio.h>
#include "s21_string.h"

void s21_strlen_test() {
    const char *test1 = "Hello";
    const char *test2 = "";
    const char *test3 = "Hello World";
    const char *test4 = "1234567890";

    int result;
    int expected;

    result = s21_strlen(test1);
    expected = 5;
    printf("Input: \"%s\", Output: %d, Expected: %d, %s\n",
           test1, result, expected,
           result == expected ? "SUCCESS" : "FAIL");

    result = s21_strlen(test2);
    expected = 0;
    printf("Input: \"%s\", Output: %d, Expected: %d, %s\n",
           test2, result, expected,
           result == expected ? "SUCCESS" : "FAIL");

    result = s21_strlen(test3);
    expected = 11;
    printf("Input: \"%s\", Output: %d, Expected: %d, %s\n",
           test3, result, expected,
           result == expected ? "SUCCESS" : "FAIL");

    result = s21_strlen(test4);
    expected = 10;
    printf("Input: \"%s\", Output: %d, Expected: %d, %s\n",
           test4, result, expected,
           result == expected ? "SUCCESS" : "FAIL");
}

int main() {
    s21_strlen_test();

    return 0;
}