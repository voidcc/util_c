#include <stdio.h>

int quicksort(int array[], int low, int high){
	int pivotpos;
	if(low < high){
		pivotpos = partition(array, low, high);
		quicksort(array, low, pivotpos);
		quicksort(array, pivotpos+1, high);
	}
	return 0;
}

int partition(int array[], int i, int j){
	int t,s;
	while(i < j){
		t = array[i];
		while(i < j && array[j] > t){
			j--;
		}
		if(i < j){
			array[i++] = array[j];
		}
		while(i < j && array[i] < t){
			i++;
		}
		if(i < j){
			array[j--] = array[i];
		}
	}
	array[i] = t;
	return i;
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
	quicksort(a, 0, 5);
	testprint(a, 6);
	return 0;
}