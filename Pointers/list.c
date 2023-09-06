/* 
 * A simple linked-list structure.
 */
#include <stdio.h>
#include <stdlib.h>

/* define a struct to store a list node */
struct node
{
    int data;
    struct node *next;
};


/* linked list functions */
struct node *alloc_node(int data);
void list_insert(struct node *prev, struct node *node);
void remove_next(struct node *prev);


int main()
{
    struct node dummy; 
    struct node *ptr;

    /* terminate the dummy node */
    dummy.next = NULL;

    /* build a list that goes 1, 2, 3 */
    list_insert(&dummy, alloc_node(1));
    list_insert(dummy.next, alloc_node(2));
    list_insert(dummy.next->next, alloc_node(3));

    /* traverse the list and print it out */
    for(ptr = dummy.next; ptr; ptr = ptr->next) {
        printf("%d\n", ptr->data);
    }

    /* destroy the list */
    while(dummy.next) {
        remove_next(&dummy);
    }
}


/* Create a new node, with a null next pointer and the given data */
struct node *alloc_node(int data)
{
    struct node *result;    

    /* create and populate the node */
    result = malloc(sizeof(struct node));
    result->data = data;
    result->next = NULL;

    return result;
}

/* insert node after prev */
void list_insert(struct node *prev, struct node *node)
{
    /* link in previous's next */
    node->next = prev->next;

    /* link in the node */
    prev->next = node;
}

/* remove the node after prev */
void remove_next(struct node *prev)
{
    struct node *doomed;
    
    /* check to see if this is the tail of the list */
    if(!prev->next) return;

    /* unlink */
    doomed = prev->next;
    prev->next = doomed->next;

    /* deallocate the doomed node */
    free(doomed);
}