#include "adds.h"

t_node *tree(node **heads)
{

    node *tmp = NULL;
    node *tmp_prev = NULL;
    t_node *root = NULL;

    for (uint8_t i = 0; i < MAXTHREAD; i++) {

        tmp = heads[i];

        while(tmp) {

            insert_node(&root, tmp->factor1, tmp->factor2);

            tmp_prev = tmp;
            tmp = (node*)tmp->next;
            tmp_prev->next = NULL;
            memset(tmp_prev, 0, sizeof(node));
            free(tmp_prev);

        }

    }

    return root;

}

t_node *create_node(double x, double y)
{

    t_node *tmp = malloc(sizeof(t_node));
    if(!tmp) return NULL;
    memset(tmp, 0, sizeof(t_node));

    tmp->factor1 = x;
    tmp->factor2 = y;

    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;

}

bool insert_node(t_node **rootptr, double x, double y)
{

    t_node *root = (t_node*)*rootptr;

    if (root == NULL) {
        *rootptr = create_node(x, y);
        return true;
    }

    if (x == root->factor1) {
        return false;
    }

    if (x < root->factor1) {
        insert_node((t_node**)&(root->left), x, y);
        return true;
    }
    else {
        insert_node((t_node**)&(root->right), x, y);
        return true;
    }


}

void print_tree(t_node *root)
{

    if (root == NULL){
        return;
    }

    print_tree((t_node*)root->left);

    printf("(%.lf, %.lf)\n",root->factor1, root->factor2);

    print_tree((t_node*)root->right);

    root->left = NULL;
    root->right = NULL;
    memset(root, 0, sizeof(t_node));
    free(root);

}
