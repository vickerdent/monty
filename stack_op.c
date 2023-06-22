#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>

/**
 * push - check the code
 *
 * @top: argument
 * @bot: argument
 * @val: argument
 * @mode: argument
 */
void push(stack_t **top, stack_t **bot, int val, int mode)
{
stack_t *ptr;

ptr = malloc(sizeof(stack_t));
if (ptr == NULL)
{
printf("Error: malloc failed\n");
exiting(EXIT_FAILURE, NULL, *top);
}
ptr->n = val;
if (*top == NULL)
{
ptr->prev = NULL;
ptr->next = NULL;
*top = ptr;
*bot = ptr;
}
else if (mode == STACKMODE)
{
ptr->next = NULL;
ptr->prev = *top;
(*top)->next = ptr;
*top = ptr;
}
else if (mode == QUEUEMODE)
{
ptr->prev = NULL;
ptr->next = *bot;
(*bot)->prev = ptr;
*bot = ptr;
}
}

/**
 * pop - check the code
 *
 * @top: top of stack
 */
void pop(stack_t **top)
{
stack_t *ptr = *top;

if (ptr == NULL)
exiting(EXIT_FAILURE, "can't pop an empty stack", *top);
if (ptr->prev == NULL)
{
free(*top);
*top = NULL;
}
else
{
ptr = ptr->prev;
ptr->next = NULL;
free(*top);
*top = ptr;
}
}

/**
 * swap - check the code
 *
 * @top: serves as top of stack
 * @bot: bottom of stack
 */
void swap(stack_t **top, stack_t **bot)
{
stack_t *ptr = *top;

if (ptr == NULL || ptr->prev == NULL)
exiting(EXIT_FAILURE, "can't swap, stack too short", *top);
ptr = ptr->prev;
(*top)->prev = ptr->prev;
ptr->next = (*top)->next;
ptr->prev = *top;
(*top)->next = ptr;
*top = ptr;
if ((*bot)->prev != NULL)
*bot = (*bot)->prev;
}

/**
 * rotl - check the code
 *
 * @top: top of stack
 * @bot: bottom of stack
 */
void rotl(stack_t **top, stack_t **bot)
{
stack_t *ptrt = *top, *ptrb = *bot;

if (ptrt == NULL || ptrt->prev == NULL)
return;
ptrt->next = ptrb;
ptrb->prev = ptrt;
*top = ptrt->prev;
(*top)->next = NULL;
*bot = ptrt;
ptrt->prev = NULL;
}

/**
 * rotr - serves to check the code
 *
 * @top: top of stack
 * @bot: bottom of stack
 */
void rotr(stack_t **top, stack_t **bot)
{
stack_t *ptrt = *top, *ptrb = *bot;

if (ptrt == NULL || ptrt->prev == NULL)
return;
ptrt->next = ptrb;
ptrb->prev = ptrt;
*bot = ptrb->next;
(*bot)->prev = NULL;
*top = ptrb;
ptrb->next = NULL;
}
