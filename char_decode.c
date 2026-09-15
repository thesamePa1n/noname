#include <stdio.h>

void encode(char c) {
    printf("%02X", c);
}

int decode(char a, char b) {
    int x, y;

    if (a >= '0' && a <= '9')
        x = a - '0';
    else if (a >= 'A' && a <= 'F')
        x = a - 'A' + 10;
    else
        return -1;

    if (b >= '0' && b <= '9')
        y = b - '0';
    else if (b >= 'A' && b <= 'F')
        y = b - 'A' + 10;
    else
        return -1;

    return x * 16 + y;
}

int main(int argc, char *argv[]) {
    if (argc != 2 || (argv[1][0] != '0' && argv[1][0] != '1')) {
        printf("n/a");
        return 0;
    }

    int mode = argv[1][0] - '0';
    int c, d, value;
    int first = 1;

    if (mode == 0) {
        while ((c = getchar()) != '\n' && c != EOF) {
            if (c == ' ')
                continue;

            d = getchar();

            if (d != ' ' && d != '\n' && d != EOF) {
                printf("n/a");
                return 0;
            }

            if (!first)
                printf(" ");

            encode(c);
            first = 0;

            if (d == '\n' || d == EOF)
                break;
        }
    } else {
        while ((c = getchar()) != '\n' && c != EOF) {
            if (c == ' ')
                continue;

            d = getchar();

            if (d == ' ' || d == '\n' || d == EOF) {
                printf("n/a");
                return 0;
            }

            value = decode(c, d);

            if (value < 0 || value > 127) {
                printf("n/a");
                return 0;
            }

            c = getchar();

            if (c != ' ' && c != '\n' && c != EOF) {
                printf("n/a");
                return 0;
            }

            if (!first)
                printf(" ");

            printf("%c", value);
            first = 0;

            if (c == '\n' || c == EOF)
                break;
        }
    }

    return 0;
}