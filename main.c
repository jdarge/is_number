#include <stdio.h>
#include <ctype.h>

long double
strtold_ (const char* restrict nptr, char** restrict endptr) {

    char* p = (char*) nptr;

    while (isspace((unsigned char) *p)) {
        p++;
    }

    if (p == NULL || *p == '\0') {
        goto FAIL;
    }

    int sign = 1;
    if (*p == '-' || *p == '+') {
        sign = (*p++ == '-') ? -1 : 1;
        if (*p == '\0') {
            goto FAIL;
        }
    }

    long double result = 0.0L;
    long double power = 1.0L;

    while (isdigit((unsigned char) *p)) {
        result = result * 10.0L + (*p++ - '0');
    }

    if (*p == '.') {
        p++;

        while (isdigit((unsigned char) *p)) {
            result = result * 10.0L + (*p++ - '0');
            power *= 10.0L;
        }
    }

    result = sign * result / power;

    if (endptr != NULL) {
        *endptr = (char*) p;
    }

    return result;

    FAIL:
    endptr = NULL;
    return 0.0L;
}

int
is_number (const char* str) {

    if (str == NULL || *str == '\0') {
        return 0;
    }

    char* endptr;
    strtold_(str, &endptr);

    if (endptr == str || endptr == NULL) {
        return 0;
    }

    while (isspace((unsigned char) *endptr)) {
        endptr++;
    }

    return *endptr == '\0';
}

int
main (void) {

    const char* success[] = {
            "0", ".3", "0.3", "123", " 0  ", "123.", "12.3", "-123", "-12.3", " -0  ", " +0  ", " -.1  ", "  -12.3",
            NULL
    };

    const char* fail[] = {
            "", "+", "-", "1a", "a1", "   ", " 1 2", "hello", "1-2.3", "-12.3.3", NULL
    };

    for (int i = 0; success[i] != NULL; i++) {

        printf("success[%d]:\t", i);
        if (is_number(success[i])) {
            printf("pass\n");
        } else {
            printf("fail\n");
        }
    }

    printf("\n");

    for (int i = 0; fail[i] != NULL; i++) {
        printf("fail[%d]:\t", i);
        if (!is_number(fail[i])) {
            printf("pass\n");
        } else {
            printf("fail\n");
        }
    }

    return 0;
}
