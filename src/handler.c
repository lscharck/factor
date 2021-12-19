#include "adds.h"

extern double n;

int get_number()
{

    char *endptr = NULL;
    char val[BUFF];
    int errnu = 0;

    printf(ANSI_COLOR_GREEN "Enter a Number: " ANSI_COLOR_RESET
            ANSI_COLOR_MAGENTA);

    if (!fgets(val, BUFF, stdin)) {
        perror("Error");
        errnu--;
        return errnu;
    }

    printf(ANSI_COLOR_RESET "" ANSI_COLOR_BLUE);

    n = strtod(val, &endptr);

    if (n == 0 && endptr == val) {
        errnu--;
        return errnu;
    }
    else if (n == HUGE_VAL || n == HUGE_VALF || n == HUGE_VALL) {
        perror("Error");
        errnu--;
        return errnu;
    }
    else if (*endptr != '\n') {
        errnu--;
        return errnu;
    }
    else if (fmax(0, n) == 0) {
        errnu--;
        return errnu;
    }
    else if (modf(n, &n) != 0) {
        errnu--;
        return errnu;
    }

    return errnu;
}
