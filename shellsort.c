#include <stdio.h>

int shellsort(int array[], int length){
	int i, j, t, increment;
	for(increment = length/2; increment > 0; increment /= 2){
		for(i = increment; i < length; i++){
			t = array[i];
			for(j = i; j >= increment && t < array[j-increment]; j -= increment){
				array[j] = array[j - increment];
			}
			array[j] = t;
		}
	}
}

int testprint(int array[], int length){
	int i;
	for(i = 0; i < length; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}

int main(){
	int a[] = {3,2,5,1,7,6};
	shellsort(a, 6);
	testprint(a, 6);
	return 0;
}