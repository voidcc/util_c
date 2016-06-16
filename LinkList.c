#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node{
	datatype data;
	struct node* next;
}linklist;

linklist* create();
int isEmpty(linklist*);
int isLast(linklist*);
int length(linklist*);
void print(linklist*);
void insert(linklist*, datatype);
linklist* find(linklist*, datatype);
linklist* findPrevious(linklist*, datatype);
void delete(linklist*, datatype);
void invert(linklist*);
void testPrint(linklist*);
void testInsert(linklist*);


void main(){
	linklist* L = create();
	//testPrint(L);
	testInsert(L);
	testPrint(L);
	//delete(L, 11);
	invert(L);
	testPrint(L);
	system("pause");
}

linklist* create(){
	linklist* head = (linklist*)malloc(sizeof(linklist));
	head->data = 0;
	head->next = NULL;
	return head;
}

int isEmpty(linklist* head){
	return head->next == NULL;
}

int isLast(linklist* p){
	return p->next == NULL;
}

int length(linklist* head){
	linklist* p = head;
	int num = 0;
	while(p->next != NULL){
		num += 1;
		p = p->next;
	}
	return num;
}

void print(linklist* head){
	linklist* p = head->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void insert(linklist* p, datatype x){
	linklist* t = (linklist*)malloc(sizeof(linklist));
	t->data = x;
	t->next = p->next;
	p->next = t;
}

linklist* find(linklist* head, datatype x){
	linklist* p = head->next;
	while(p != NULL && p->data != x){
		p = p->next;
	}
	return p;
}

linklist* findPrevious(linklist* head, datatype x){
	linklist* p = head;
	while(p->next != NULL && p->next->data != x){
		p = p->next;
	}
	if(p->next != NULL)
		return p;
	else
		return NULL;
}

void delete(linklist* head, datatype x){
	linklist* p = findPrevious(head, x);
	if(p != NULL){
		linklist* t = p->next;
		p->next = t->next;
		free(t);
	}
	else{
		printf("cannot find %d\n",x);
	}
}

void invert(linklist* head){
	linklist* p = head->next;
	linklist* t;
	while(p->next != NULL){
		t = p->next;
		p->next = t->next;
		t->next = head->next;
		head->next = t;
	}
}

void testPrint(linklist* head){
	if(isEmpty(head) == 1){
		printf("isEmpty: yes\n");
	}
	else{
		printf("isEmpty: no\n");
	}
	printf("length: %d\n",length(head));
	printf("print:");
	print(head);
}

void testInsert(linklist* head){
	linklist* p = head;
	int i;
	for(i = 1; i <= 10; i++){
		insert(p, i);
		p = p->next;
	}
	//free(p);
}