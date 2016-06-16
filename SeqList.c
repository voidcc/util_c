#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
typedef int datatype;
//const int maxsize = 1024;
typedef struct{
	datatype data[maxsize];
	int last;
}sequenlist;

//void create(sequenlist*);
sequenlist* create();
void print(sequenlist*);

void main(){
	sequenlist* L = create();
	//sequenlist* L; 
	//create(L);
	print(L);
}
/*
void create(sequenlist* Lp){
	Lp = (sequenlist*)malloc(sizeof(sequenlist));
	Lp->last = 0;
	//print(L);
	for(int i = 0; i < 5; i++){
		Lp->data[Lp->last] = i;
		Lp->last += 1;
	}
	print(Lp);
}
*/

sequenlist* create(){
	sequenlist* L = (sequenlist*)malloc(sizeof(sequenlist));
	L->last = 0;
	for(int i = 0; i < 5; i++){
		L->data[L->last] = i;
		L->last += 1;
	}
	return L;
}

void print(sequenlist* L){
	printf("last: %d\n", L->last);
	printf("data: ");
	for(int i = 0; i < L->last; i++){
		printf("%d ", L->data[i]);
	}
	printf("\n");
}
