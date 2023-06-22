#include "monty.h"
/**
 * f_queue – serves to print the top
 * @head: serves as stack head
 * @counter: serves as line_number
 * Return: no return
*/
void f_queue(stack_t **head, unsigned int counter)
{
(void)head;
(void)counter;
bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: serves as new_value
 * @head: serves as head of the stack
 * Return: no return
*/
void addqueue(stack_t **head, int n)
{
stack_t *new_node, *aux;

aux = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
}
new_node->n = n;
new_node->next = NULL;
if (aux)
{
while (aux->next)
aux = aux->next;
}
if (!aux)
{
*head = new_node;
new_node->prev = NULL;
}
else
{
aux->next = new_node;
new_node->prev = aux;
}
}
