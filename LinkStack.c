#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node{
	datatype data;
	struct node* next;
}stack;

stack* setnull();
void push(stack*, datatype);
datatype pop(stack*);
int isEmpty(stack*);
void print(stack*);
void testpush(stack*);
void testpop(stack*);

void main(){
	stack* s = setnull();
	testpush(s);
	print(s);
	testpop(s);
	print(s);
}

stack* setnull(){
	stack* head = (stack*)malloc(sizeof(stack));
	head->next = NULL;
}

void push(stack* head, datatype x){
	stack* t = (stack*)malloc(sizeof(stack));
	t->data = x;
	t->next = head->next;
	head->next = t;
}

datatype pop(stack* head){
	if(!isEmpty(head)){
		stack* t = head->next;
		head->next = t->next;
		datatype d = t->data;
		free(t);
		return d;
	}
}

int isEmpty(stack* head){
	return head->next == NULL;
}

void print(stack* head){
	stack* p = head->next;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void testpush(stack* head){
	int i;
	for(i = 0; i < 10; i++){
		push(head, i);
	}
}

void testpop(stack* head){
	printf("%d\n", pop(head));
}