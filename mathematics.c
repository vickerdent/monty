#include "monty.h"

#include <stdio.h>

/**
 * add - check the code
 *
 * @top: top of stack
 */
void add(stack_t **top)
{
stack_t *ptr = *top;
long num;

if (ptr == NULL || ptr->prev == NULL)
exiting(EXIT_FAILURE, "can't add, stack too short", *top);
else
{
num = ptr->n;
ptr = ptr->prev;
ptr->next = NULL;
free(*top);
*top = ptr;
ptr->n += num;
}
}

/**
 * sub - check the code
 *
 * @top: top of stack
 */
void sub(stack_t **top)
{
stack_t *ptr = *top;
long num;

if (ptr == NULL || ptr->prev == NULL)
exiting(EXIT_FAILURE, "can't sub, stack too short", *top);
else
{
num = ptr->n;
ptr = ptr->prev;
ptr->next = NULL;
free(*top);
*top = ptr;
ptr->n -= num;
}
}

/**
 * mul - check the code
 *
 * @top: top of stack
 */
void mul(stack_t **top)
{
stack_t *ptr = *top;
long num;

if (ptr == NULL || ptr->prev == NULL)
exiting(EXIT_FAILURE, "can't mul, stack too short", *top);
else
{
num = ptr->n;
ptr = ptr->prev;
ptr->next = NULL;
free(*top);
*top = ptr;
ptr->n *= num;
}
}

/**
 * _div - check the code
 *
 * @top: top of stack
 */
void _div(stack_t **top)
{
stack_t *ptr = *top;
long num;

if (ptr == NULL || ptr->prev == NULL)
exiting(EXIT_FAILURE, "can't div, stack too short", *top);
else
{
num = ptr->n;
if (num == 0)
exiting(EXIT_FAILURE, "division by zero", *top);
ptr = ptr->prev;
ptr->next = NULL;
free(*top);
*top = ptr;
ptr->n /= num;
}
}

/**
 * mod - check the code
 *
 * @top: top of stack
 */
void mod(stack_t **top)
{
stack_t *ptr = *top;
long num;

if (ptr == NULL || ptr->prev == NULL)
exiting(EXIT_FAILURE, "can't mod, stack too short", *top);
else
{
num = ptr->n;
if (num == 0)
exiting(EXIT_FAILURE, "division by zero", *top);
ptr = ptr->prev;
ptr->next = NULL;
free(*top);
*top = ptr;
ptr->n %= num;
}
}
