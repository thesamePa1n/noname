#include <stdio.h>
#include <stdlib.h>

#define MAX_TEXT 100
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 101

int word_length(const char *word) {
    int i = 0;

    while (word[i] != '\0') {
        i++;
    }

    return i;
}

int valid_key(int argc, char *argv[]) {
    return argc == 2 &&
           argv[1][0] == '-' &&
           argv[1][1] == 'w' &&
           argv[1][2] == '\0';
}

int read_input(char *text) {
    int i = 0;
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i >= MAX_TEXT) {
            return 0;
        }

        text[i] = (char)ch;
        i++;
    }

    if (ch != '\n') {
        return 0;
    }

    text[i] = '\0';

    return 1;
}

int split_words(char *text, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    int i = 0;
    int j;
    int count = 0;

    while (text[i] != '\0') {
        while (text[i] == ' ') {
            i++;
        }

        if (text[i] == '\0') {
            break;
        }

        j = 0;

        while (text[i] != '\0' && text[i] != ' ') {
            if (j >= MAX_WORD_LENGTH - 1) {
                return -1;
            }

            words[count][j] = text[i];
            j++;
            i++;
        }

        words[count][j] = '\0';
        count++;

        if (count >= MAX_WORDS) {
            return -1;
        }
    }

    return count;
}

void print_normal_line(char words[MAX_WORDS][MAX_WORD_LENGTH],
                       int start,
                       int end,
                       int width,
                       int last) {
    int total_length = 0;
    int gaps;
    int spaces;
    int base_spaces;
    int extra_spaces;
    int i;
    int j;

    for (i = start; i <= end; i++) {
        total_length += word_length(words[i]);
    }

    gaps = end - start;

    if (last || gaps == 0) {
        for (i = start; i <= end; i++) {
            if (i > start) {
                putchar(' ');
            }

            j = 0;
            while (words[i][j] != '\0') {
                putchar(words[i][j]);
                j++;
            }
        }

        return;
    }

    spaces = width - total_length;
    base_spaces = spaces / gaps;
    extra_spaces = spaces % gaps;

    for (i = start; i <= end; i++) {
        j = 0;

        while (words[i][j] != '\0') {
            putchar(words[i][j]);
            j++;
        }

        if (i < end) {
            int count = base_spaces;

            if (extra_spaces > 0) {
                count++;
                extra_spaces--;
            }

            while (count > 0) {
                putchar(' ');
                count--;
            }
        }
    }
}

void print_long_word(const char *word, int start, int width) {
    int length = word_length(word);
    int position = start;
    int remaining;
    int take;
    int i;

    while (1) {
        remaining = length - position;

        if (remaining <= width) {
            for (i = position; i < length; i++) {
                putchar(word[i]);
            }

            break;
        }

        take = width - 1;

        for (i = 0; i < take; i++) {
            putchar(word[position + i]);
        }

        putchar('-');
        putchar('\n');

        position += take;
    }
}

int main(int argc, char *argv[]) {
    int width;
    int ch;
    char text[MAX_TEXT + 1];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int count;
    int current = 0;
    int line_start;
    int line_end;
    int line_length;
    int next_length;
    int i;
    int first_output = 1;

    if (!valid_key(argc, argv)) {
        printf("n/a");
        return 0;
    }

    if (scanf("%d", &width) != 1 || width < 2) {
        printf("n/a");
        return 0;
    }

    ch = getchar();

    if (ch != '\n') {
        printf("n/a");
        return 0;
    }

    if (!read_input(text)) {
        printf("n/a");
        return 0;
    }

    count = split_words(text, words);

    if (count < 0) {
        printf("n/a");
        return 0;
    }

    while (current < count) {
        line_start = current;
        line_end = current;
        line_length = word_length(words[current]);

        if (line_length > width) {
            if (!first_output) {
                putchar('\n');
            }

            print_long_word(words[current], 0, width);
            first_output = 0;
            current++;

            if (current < count) {
                putchar('\n');
            }

            continue;
        }

        while (line_end + 1 < count) {
            next_length = word_length(words[line_end + 1]);

            if (next_length > width) {
                break;
            }

            if (line_length + 1 + next_length > width) {
                break;
            }

            line_end++;
            line_length += 1 + next_length;
        }

        if (line_end + 1 < count &&
            word_length(words[line_end + 1]) > width) {
            int available = width - line_length;

            if (available >= 2) {
                int fragment_length = available - 1;

                if (!first_output) {
                    putchar('\n');
                }

                for (i = line_start; i <= line_end; i++) {
                    if (i > line_start) {
                        putchar(' ');
                    }

                    printf("%s", words[i]);
                }

                putchar(' ');

                for (i = 0; i < fragment_length; i++) {
                    putchar(words[line_end + 1][i]);
                }

                putchar('-');

                current = line_end + 1;

                if (fragment_length < word_length(words[current])) {
                    print_long_word(words[current],
                                    fragment_length,
                                    width);
                    current++;
                }

                first_output = 0;

                if (current < count) {
                    putchar('\n');
                }

                continue;
            }
        }

        if (!first_output) {
            putchar('\n');
        }

        print_normal_line(words,
                          line_start,
                          line_end,
                          width,
                          line_end == count - 1);

        first_output = 0;
        current = line_end + 1;
    }

    return 0;
}