#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

typedef int datatype;
typedef struct{
	datatype data[maxsize];
	int top;
}stack;

stack* setnull();
void push(stack*, datatype);
datatype pop(stack*);
void print(stack*);
int isEmpty(stack*);
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
	head->top = -1;
	return head;
}

void push(stack* head, datatype x){
	if(head->top + 1 < maxsize)
		head->data[++head->top] = x;
	else
		printf("out of space\n");
}

datatype pop(stack* head){
	if(!isEmpty(head))
		return head->data[head->top--];
	else
		printf("empty");
		return -1;  //????
}

int isEmpty(stack* head){
	return head->top == -1;
}

void print(stack* head){
	if(head->top >= 0){
		int i;
		for(i = head->top; i >= 0; i--){
			printf("%d ",head->data[i]);
		}
		printf("\n");
	}
}

void testpush(stack* head){
	int i;
	for(i = 0; i <= 7; i++){
		push(head, i);
	}
}

void testpop(stack* head){
	int i;
	printf("%d\n",pop(head));
}