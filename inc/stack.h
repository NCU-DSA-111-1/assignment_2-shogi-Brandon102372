#ifndef STACK_H
#define STACK_H

#include "coord.h"
#include "step.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
	step value;
	struct stack *next;
}stack;
/*check if stack is empty*/
bool isEmpty(stack *st);
/*push an element into the stack*/
stack push(stack **st,step data);
/*pop out an element from the stack*/
step pop(stack **st);
/*print all the elements in the stack*/
void print_stack(stack **st);
#endif
