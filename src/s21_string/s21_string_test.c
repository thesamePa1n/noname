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

void s21_strcmp_test() {
    const char *str1;
    const char *str2;
    int result;
    int success;

    str1 = "hello";
    str2 = "hello";
    result = s21_strcmp(str1, str2);
    success = result == 0;
    printf("Input: \"%s\", \"%s\", Output: %d, %s\n",
           str1, str2, result,
           success ? "SUCCESS" : "FAIL");

    str1 = "abc";
    str2 = "abd";
    result = s21_strcmp(str1, str2);
    success = result < 0;
    printf("Input: \"%s\", \"%s\", Output: %d, %s\n",
           str1, str2, result,
           success ? "SUCCESS" : "FAIL");

    str1 = "abd";
    str2 = "abc";
    result = s21_strcmp(str1, str2);
    success = result > 0;
    printf("Input: \"%s\", \"%s\", Output: %d, %s\n",
           str1, str2, result,
           success ? "SUCCESS" : "FAIL");

    str1 = "";
    str2 = "";
    result = s21_strcmp(str1, str2);
    success = result == 0;
    printf("Input: \"%s\", \"%s\", Output: %d, %s\n",
           str1, str2, result,
           success ? "SUCCESS" : "FAIL");

    str1 = "hello";
    str2 = "hello world";
    result = s21_strcmp(str1, str2);
    success = result < 0;
    printf("Input: \"%s\", \"%s\", Output: %d, %s\n",
           str1, str2, result,
           success ? "SUCCESS" : "FAIL");
}

int main() {
    s21_strlen_test();
    s21_strcmp_test();

    return 0;
}