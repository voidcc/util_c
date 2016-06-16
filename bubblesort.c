 #include <stdio.h>

int bubblesort(int array[], int length){
	int i, j, t;
	for(i = length; i > 0; i--){
		for(j = 1; j < i; j++){
			if(array[j] < array[j-1]){
				t = array[j];
				array[j] = array[j-1];
				array[j-1] = t;
			}
		}
	}
	return 0;
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
	int i, a[] = {3,2,5,1,7,6};
	bubblesort(a, 6);
	testprint(a, 6);
	return 0;
}