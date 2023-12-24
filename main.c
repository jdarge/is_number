#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isNumber(const char *str) {

    if (str == NULL || *str == '\0') {
       return 0;
    }

    char *endptr;
    strtold(str, &endptr);

    if (endptr == str) {
        return 0;
    }

    while (isspace((unsigned char)*endptr)) {
        endptr++;
    }

    return *endptr == '\0';
}

int main() {

    printf("isNumber? %s\n", isNumber("0")      ? "yes" : "no");
    printf("isNumber? %s\n", isNumber("123")    ? "yes" : "no");
    printf("isNumber? %s\n", isNumber("123.")   ? "yes" : "no");
    printf("isNumber? %s\n", isNumber("12.3")   ? "yes" : "no");
    printf("isNumber? %s\n", isNumber("-123")   ? "yes" : "no");
    printf("isNumber? %s\n", isNumber("-12.3")  ? "yes" : "no");
    printf("isNumber? %s\n", isNumber("  -12.3")? "yes" : "no");
    printf("isNumber? %s\n", isNumber(" 0  ")   ? "yes" : "no");
    printf("\n");
    printf("isNumber? %s\n", isNumber(" 1 2")   ? "yes" : "no");
    printf("isNumber? %s\n", isNumber("")       ? "yes" : "no");
    printf("isNumber? %s\n", isNumber("   ")    ? "yes" : "no");
    printf("isNumber? %s\n", isNumber("-12.3.3")? "yes" : "no");
    printf("isNumber? %s\n", isNumber("1-2.3")  ? "yes" : "no");
    printf("isNumber? %s\n", isNumber("hello")  ? "yes" : "no");
    printf("isNumber? %s\n", isNumber("1a")     ? "yes" : "no");
    printf("isNumber? %s\n", isNumber("a1")     ? "yes" : "no");

    return 0;
}
