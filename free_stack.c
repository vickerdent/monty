#include "monty.h"
/**
 * f_div - serves to divide the top two elements of the stack.
 * @head: serves as stack head
 * @counter: serves as line_number
 * Return: no return
*/
void f_div(stack_t **head, unsigned int counter)
{
    stack_t *h;
    int len = 0, aux;

    h = *head;
    while (h)
    {
        h = h->next;
        len++;
    }
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    if (h->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    aux = h->next->n / h->n;
    h->next->n = aux;
    *head = h->next;
    free(h);
}


/**
* free_stack - serves to free a doubly linked list
* @head: serves as head of the stack
*/
void free_stack(stack_t *head)
{
    stack_t *aux;

    aux = head;
    while (head)
    {
        aux = head->next;
        free(head);
        head = aux;
    }
}
