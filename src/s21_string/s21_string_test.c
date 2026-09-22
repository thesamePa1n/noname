#include <stdio.h>
#include "s21_string.h"

void s21_strlen_test() {
    const char *test1 = "Hello";
    const char *test2 = "";
    const char *test3 = "Hello World";

    int result;
    int expected;

    result = s21_strlen(test1);
    expected = 5;
    printf("s21_strlen: \"%s\" -> %d, expected %d, %s\n",
           test1, result, expected,
           result == expected ? "SUCCESS" : "FAIL");

    result = s21_strlen(test2);
    expected = 0;
    printf("s21_strlen: \"%s\" -> %d, expected %d, %s\n",
           test2, result, expected,
           result == expected ? "SUCCESS" : "FAIL");

    result = s21_strlen(test3);
    expected = 11;
    printf("s21_strlen: \"%s\" -> %d, expected %d, %s\n",
           test3, result, expected,
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
    printf("s21_strcmp: \"%s\", \"%s\" -> %d, %s\n",
           str1, str2, result,
           success ? "SUCCESS" : "FAIL");

    str1 = "abc";
    str2 = "abd";
    result = s21_strcmp(str1, str2);
    success = result < 0;
    printf("s21_strcmp: \"%s\", \"%s\" -> %d, %s\n",
           str1, str2, result,
           success ? "SUCCESS" : "FAIL");

    str1 = "abd";
    str2 = "abc";
    result = s21_strcmp(str1, str2);
    success = result > 0;
    printf("s21_strcmp: \"%s\", \"%s\" -> %d, %s\n",
           str1, str2, result,
           success ? "SUCCESS" : "FAIL");

    str1 = "";
    str2 = "";
    result = s21_strcmp(str1, str2);
    success = result == 0;
    printf("s21_strcmp: \"%s\", \"%s\" -> %d, %s\n",
           str1, str2, result,
           success ? "SUCCESS" : "FAIL");
}

void s21_strcpy_test() {
    char dest[50];
    char *result;
    int success;

    result = s21_strcpy(dest, "Hello");
    success = result == dest && s21_strcmp(dest, "Hello") == 0;
    printf("s21_strcpy: \"Hello\" -> \"%s\", %s\n",
           dest, success ? "SUCCESS" : "FAIL");

    result = s21_strcpy(dest, "");
    success = result == dest && s21_strcmp(dest, "") == 0;
    printf("s21_strcpy: \"\" -> \"%s\", %s\n",
           dest, success ? "SUCCESS" : "FAIL");

    result = s21_strcpy(dest, "Hello World");
    success = result == dest && s21_strcmp(dest, "Hello World") == 0;
    printf("s21_strcpy: \"Hello World\" -> \"%s\", %s\n",
           dest, success ? "SUCCESS" : "FAIL");

    result = s21_strcpy(dest, "123456789");
    success = result == dest && s21_strcmp(dest, "123456789") == 0;
    printf("s21_strcpy: \"123456789\" -> \"%s\", %s\n",
           dest, success ? "SUCCESS" : "FAIL");
}

void s21_strcat_test() {
    char dest[50];
    char *result;
    int success;

    s21_strcpy(dest, "Hello ");
    result = s21_strcat(dest, "World");
    success = result == dest && s21_strcmp(dest, "Hello World") == 0;
    printf("s21_strcat: \"Hello \" + \"World\" -> \"%s\", %s\n",
           dest, success ? "SUCCESS" : "FAIL");

    s21_strcpy(dest, "");
    result = s21_strcat(dest, "Hello");
    success = result == dest && s21_strcmp(dest, "Hello") == 0;
    printf("s21_strcat: \"\" + \"Hello\" -> \"%s\", %s\n",
           dest, success ? "SUCCESS" : "FAIL");

    s21_strcpy(dest, "Hello");
    result = s21_strcat(dest, "");
    success = result == dest && s21_strcmp(dest, "Hello") == 0;
    printf("s21_strcat: \"Hello\" + \"\" -> \"%s\", %s\n",
           dest, success ? "SUCCESS" : "FAIL");

    s21_strcpy(dest, "123");
    result = s21_strcat(dest, "456");
    success = result == dest && s21_strcmp(dest, "123456") == 0;
    printf("s21_strcat: \"123\" + \"456\" -> \"%s\", %s\n",
           dest, success ? "SUCCESS" : "FAIL");
}

void s21_strchr_test() {
    const char *str = "Hello World";
    char *result;
    int success;

    result = s21_strchr(str, 'H');
    success = result != 0 && s21_strcmp(result, "Hello World") == 0;
    printf("s21_strchr: \"%s\", 'H' -> \"%s\", %s\n",
           str, result, success ? "SUCCESS" : "FAIL");

    result = s21_strchr(str, 'o');
    success = result != 0 && s21_strcmp(result, "o World") == 0;
    printf("s21_strchr: \"%s\", 'o' -> \"%s\", %s\n",
           str, result, success ? "SUCCESS" : "FAIL");

    result = s21_strchr(str, 'x');
    success = result == 0;
    printf("s21_strchr: \"%s\", 'x' -> %s, %s\n",
           str, result == 0 ? "NULL" : result,
           success ? "SUCCESS" : "FAIL");

    result = s21_strchr(str, '\0');
    success = result != 0 && *result == '\0';
    printf("s21_strchr: \"%s\", '\\0' -> %s, %s\n",
           str, result != 0 ? "found" : "NULL",
           success ? "SUCCESS" : "FAIL");
}

void s21_strstr_test() {
    const char *str = "Hello World";
    char *result;
    int success;

    result = s21_strstr(str, "Hello");
    success = result != 0 && s21_strcmp(result, "Hello World") == 0;
    printf("s21_strstr: \"%s\", \"Hello\" -> \"%s\", %s\n",
           str, "Hello", success ? "SUCCESS" : "FAIL");

    result = s21_strstr(str, "World");
    success = result != 0 && s21_strcmp(result, "World") == 0;
    printf("s21_strstr: \"%s\", \"World\" -> \"%s\", %s\n",
           str, "World", success ? "SUCCESS" : "FAIL");

    result = s21_strstr(str, "xyz");
    success = result == 0;
    printf("s21_strstr: \"%s\", \"xyz\" -> %s, %s\n",
           str, result == 0 ? "NULL" : result,
           success ? "SUCCESS" : "FAIL");

    result = s21_strstr(str, "");
    success = result == str;
    printf("s21_strstr: \"%s\", \"\" -> beginning, %s\n",
           str, success ? "SUCCESS" : "FAIL");
}

int main() {
    s21_strlen_test();
    s21_strcmp_test();
    s21_strcpy_test();
    s21_strcat_test();
    s21_strchr_test();
    s21_strstr_test();

    return 0;
}