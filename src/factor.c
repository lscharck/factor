#include "adds.h"

extern double n;

void *factoring(void *ind)
{

    uint8_t x = *((uint8_t*)ind);
    node *tmp = NULL, *head = NULL;

    for (uint32_t i=x; i <= floor(sqrt(n)); i+=MAXTHREAD) {

            if ( fmod(n, i) == 0 ) {

                tmp = create_new_node(i, n/i);

                insert_at_head(&head, tmp);

            }
    }

    return (void*)head;

}
