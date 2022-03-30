// Practice Problem 2.13, P. 92
#include <stdio.h>
#include <string.h>

int bis(int, int);
int bic(int, int);
int bool_or(int, int);
int bool_xor(int, int);
int display(int (*f)(int, int), int, int, char *);

int main(void) {
    for (int j = 0; j <= 1; j++) {
        for (int i = 0; i <=1; i++) {
            if (display(bool_or, i, j, "OR")) {
                puts("Something went wrong!");
            }
        }
    }
    for (int j = 0; j <= 1; j++) {
        for (int i = 0; i <=1; i++) {
            if (display(bool_xor, i, j, "XOR")) {
                puts("Something went wrong!");
            }
        }
    }
    return 0;
}

int bis(int x, int m) {
    return x | m;
}

int bic(int x, int m) {
    return (x | m) - m;
}

int bool_or(int x, int y) {
    return bis(x, y);
}

int bool_xor(int x, int y) {
    return bis(bic(x, y), bic(y, x));
}

int display(int (*f)(int, int), int x, int y, char *option) {
    if (!strcmp(option, "OR")) {
        printf("%d OR %d: %d\n", x, y, f(x, y));
        return 0;
    } else if (!strcmp(option, "XOR")) {
        printf("%d XOR %d: %d\n", x, y, f(x, y));
        return 0;
    } else {
        return 1;
    }
}