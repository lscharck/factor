#include "adds.h"

node *create_new_node(double x, double y)
{
    node *tmp = malloc(sizeof(node));
    if(!tmp) perror("Error");
    memset(tmp,0,sizeof(node));

    tmp->factor1 = x;
    tmp->factor2 = y;
    tmp->next = NULL;

    return tmp;
}

void insert_at_head(node **head, node *tmp)
{
    tmp->next = (struct node*)*head;
    *head = tmp;
}
