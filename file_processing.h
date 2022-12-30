#ifndef FILE_PROCESSING
#define FILE_PROCESSING
#include <string.h>
#include <stdio.h>
#include "stack.h"
#include "step.h"
/*Write game record to file*/
void write_file(stack* st,const char *name);
/*Read game record from file*/
void read_file(stack** st,const char *name);
#endif
