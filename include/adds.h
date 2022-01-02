#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <inttypes.h>
#define ANSI_COLOR_RED     "\x1b[91m"
#define ANSI_COLOR_GREEN   "\x1b[38;2;0;204;0m"
#define ANSI_COLOR_BLUE   "\x1b[38;2;51;85;255m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_MAGENTA   "\x1b[38;2;255;25;217m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define MAXTHREAD 8
#define BUFF 21
#define TIME 1000000000.0
#define bool _Bool
#define true 1
#define false 0

extern double n; // declared here for all TUs, defined in handler

typedef struct
{
    double factor1;
    double factor2;
    struct node *next;
}node;

typedef struct
{
    double factor1;
    double factor2;
    struct t_node *left, *right;
}t_node;

int get_number();

void *factoring(void *i);

node *create_new_node(double x, double y);

void insert_at_head(node **head, node *tmp);

t_node *tree(node **heads);

t_node *create_node(double x, double y);

bool insert_node(t_node **root, double x, double y);

void print_tree(t_node *root);

void print_linked_list(node **heads);

#endif // HEADER_H
