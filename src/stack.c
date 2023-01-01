#include "../inc/stack.h"

bool isEmpty(stack *st){
	return st==NULL;
} 

stack push(stack ** const st,step data){
	stack* new=(stack*)malloc(sizeof(stack));
	if (new==NULL){
		printf("kkkkkkkkkk\n");
	}
	new->value=data;
	new->next=(*st);
	*st=new;
} 

step pop(stack ** const st){
	step data;
	if(isEmpty(*st)){
		//printf("stack is empty\n");
	}else{
		data=(*st)->value;
		stack *tmp=(*st)->next;
		free(*st);
		*st=tmp;
		return data; 
	}
}

void print_stack(stack ** const st){
	stack *cur= (*st);
	int i=0;
	while(cur!=NULL){
		//printf("%dth element\n",i);
		coord start=cur->value.start;
		coord end=cur->value.end;
		bool prom=cur->value.promote;
		short cap=cur->value.capture;
		printf("start: %d,%d end: %d,%d promote: %d capture %d\n",start.x,start.y,end.x,end.y,prom,cap);
		cur=cur->next;
		i++;
	}
}
