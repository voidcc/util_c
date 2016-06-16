 #include <stdio.h>

int insertsort(int array[], int length){
	if(length <= 1){
		return 0;
	}
	int i, j, t;
	for(i = 1; i < length; i++){
		t = array[i];
		for(j = i; j > 0; j--){
			if(t < array[j-1]){
				array[j] = array[j-1];
			}else{
				break;
			}
		}
		array[j] = t;
	}
	return 0;
}

int insertsort2(int array[], int length){
	if(length <= 1){
		return 0;
	}
	int i, j, t;
	for(i = 1; i < length; i++){
		t = array[i];
		for(j = i; j > 0 && array[j-1] > t; j--){
			array[j] = array[j-1];
		}
		array[j] = t;
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
	int a[] = {3,2,5,1,7,6};
	insertsort2(a, 6);
	testprint(a, 6);
	//int a[] = {3,2,5};
	//insertsort(a, 3);
	//testprint(a, 3);
	return 0;
}