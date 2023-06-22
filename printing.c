#include "monty.h"
#include <stdio.h>

/**
 * pall - serves to print all values as integers
 *
 * @top: top of stack
 */
void pall(stack_t **top)
{
stack_t *ptr = *top;

while (ptr != NULL)
{
printf("%d\n", ptr->n);
ptr = ptr->prev;
}
}

/**
 * pint - serves to print top of stack as an integer
 *
 * @top: top of stack
 */
void pint(stack_t **top)
{
if (*top == NULL)
exiting(EXIT_FAILURE, "can't pint, stack empty", *top);
printf("%d\n", (*top)->n);
}

/**
 * pchar - print top of stack as a char
 *
 * @top: top of stack
 */
void pchar(stack_t **top)
{
stack_t *ptr = *top;

if (ptr == NULL)
exiting(EXIT_FAILURE, "can't pchar, stack empty", *top);
if (ptr->n > 127 || ptr->n < 0)
exiting(EXIT_FAILURE, "can't pchar, value out of range", *top);
printf("%c\n", ptr->n);
}

/**
 * pstr - check the code
 *
 * @top: top of stack
 */
void pstr(stack_t **top)
{
stack_t *ptr = *top;

while (ptr != NULL && ptr->n <= 127 && ptr->n > 0)
{
printf("%c", ptr->n);
ptr = ptr->prev;
}
printf("\n");
}
