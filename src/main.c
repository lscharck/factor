#include "adds.h"

double n;

int main(void)
{

    double cpu_time = 0.0, wall_time = 0.0;
    struct timespec start1, finish1;
    struct timespec start2, finish2;
    node *result = NULL;
    t_node *root = NULL;

    pthread_t threads[MAXTHREAD];
    uint8_t index[MAXTHREAD];
    node *rtrn[MAXTHREAD];

    if (get_number() < 0) {
        printf(ANSI_COLOR_RESET "" ANSI_COLOR_RED);
        printf("Bad number!\n");
        exit(EXIT_FAILURE);
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start1);
    clock_gettime(CLOCK_MONOTONIC, &start2);

    for (uint8_t i = 0; i < MAXTHREAD; i++) {
        index[i] = i+1;
        if (pthread_create(&threads[i], NULL, factoring, &index[i]) != 0)
            perror("Error");
    }

    for (uint8_t i = 0; i < MAXTHREAD; i++) {
        pthread_join(threads[i], (void*)&result);
        rtrn[i] = result;
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish1);
    clock_gettime(CLOCK_MONOTONIC, &finish2);

    wall_time = (finish2.tv_sec - start2.tv_sec);
    wall_time += (finish2.tv_nsec - start2.tv_nsec) / TIME;
    cpu_time = (finish1.tv_sec - start1.tv_sec);
    cpu_time += (finish1.tv_nsec - start1.tv_nsec) / TIME;

    root = tree(rtrn);

    print_tree(root);

    printf(ANSI_COLOR_RESET ANSI_COLOR_RED 
            "CPU Time: %f seconds\nWall Time: %f seconds\n" ANSI_COLOR_RESET,
            cpu_time, wall_time);

    return 0;
}
