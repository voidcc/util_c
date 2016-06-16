#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


int selectSort(int* a, int n){
	int i, j;
	int temp, flag;
	if(n <= 1){
		return 0;
	}
	for(i = 0; i < n-1; i++){
		temp = a[i];
		flag = i;
		for(j = i+1; j < n; j++){
			if(a[j] < temp){
				flag = j;
				temp = a[j];
			}
		}
		if(flag != i){
			a[flag] = a[i];
			a[i] = temp;
		}
	}
	return 0;
}


int insertSort(int* a, int n){
	int i, j;
	int temp;
	if(n <= 1){
		return 0;
	}
	for(i = 1; i < n; i++){
		temp = a[i];
		for(j = i-1; j >= 0; j--){
			if(a[j] > temp){
				a[j+1] = a[j];
			}else{
				break;
			}
		}
		a[j+1] = temp;
	}
	return 0;
}


int bubbleSort(int* a, int n){
	int i, j;
	int temp;
	if(n <= 1){
		return 0;
	}
	for(i = 0; i < n-1; i++){
		for(j = 1; j < n-i; j++){
			if(a[j] < a[j-1]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
	return 0;
}


int merge(int* a, int* temp, int leftPos, int rightPos, int rightEnd){
	int i, leftEnd, tempPos, numElement;
	leftEnd = rightPos - 1;
	tempPos = leftPos;
	numElement = rightEnd - leftPos + 1;
	while(leftPos <= leftEnd && rightPos <= rightEnd){
		if(a[leftPos] <= a[rightPos]){
			temp[tempPos++] = a[leftPos++];
		}else{
			temp[tempPos++] = a[rightPos++];
		}
	}
	while(leftPos <= leftEnd){
		temp[tempPos++] = a[leftPos++];
	}
	while(rightPos <= rightEnd){
		temp[tempPos++] = a[rightPos++];
	}
	for(i = 0; i < numElement; i++, rightEnd--){
		a[rightEnd] = temp[rightEnd];
	}
	return 0;
}

int mSort(int* a, int* temp, int left, int right){
	int center;
	if(left < right){
		center = (left + right) / 2;
		mSort(a, temp, left, center);
		mSort(a, temp, center+1, right);
		merge(a, temp, left, center+1, right);
	}
	return 0;
}

int mergeSort(int* a, int n){
	int* temp;
	if(n <= 1){
		return 0;
	}
	temp = (int*)malloc(n * sizeof(int));
	if(temp != NULL){
		mSort(a, temp, 0, n-1);
		free(temp);
	}else{
		printf("Fail to malloc temp\n");
	}
	return 0;
}


int qSort(int* a, int low, int high){
	int i, j, temp;
	if(low >= high){
		return 0;
	}
	i = low;
	j = high;
	temp = a[i];
	while(i < j){
		while(i < j && a[j] >= temp){
			j--;
		}
		if(i < j){
			a[i++] = a[j];
		}
		while(i < j && a[i] <= temp){
			i++;
		}
		if(i < j){
			a[j--] = a[i];
		}
	}
	a[i] = temp;
	qSort(a, low, i);
	qSort(a, i+1, high);
	return 0;
}

int quickSort(int* a, int n){
	if(n <= 1){
		return 0;
	}
	qSort(a, 0, n-1);
	return 0;
}


int shellSort(int* a , int n){
	int i, j, temp, increment;
	if(n <= 1){
		return 0;
	}
	for(increment = n/2; increment >= 1; increment /= 2){
		for(i = increment; i < n; i++){
			temp = a[i];
			for(j = i - increment; j >= 0; j -= increment){
				if(a[j] > temp){
					a[j + increment] = a[j];
				}else{
					break;
				}
			}
			a[j + increment] = temp;
		}
	}
	return 0;
}


int percDown(int* a, int i, int n){
	int temp, child;
	for(temp = a[i]; i*2+1 <= n-1; i = child){   //i*2+1:left child
		child = i*2+1;
		if(child + 1 <= n - 1 && a[child + 1] > a[child]){  // find the max child
			child++;  // right child
		}
		if(a[child] > temp){
			a[i] = a[child];
		}else{
			break;
		}
	}
	a[i] = temp;
}

int heapSort(int* a, int n){
	int i;
	if(n <= 1){
		return 0;
	}
	for(i = n/2-1; i >= 0; i--){  // build heap, n/2-1:father node
		percDown(a, i, n);
	}
	for(i = n-1; i >= 0; i--){   // deleteMax
		swap(&a[0], &a[i]);
		percDown(a, 0, i);  //percolate down the first node
	}
	return 0;
}


int testPrint(int* array, int length){
	int i;
	for(i = 0; i < length; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}


int main(){
	int a[] = {43,25,48,12,25,65,43,57};
	int length = sizeof(a) / sizeof(a[0]);
	//selectSort(a, length);
	//insertSort(a, length);
	//bubbleSort(a, length);
	//mergeSort(a, length);
	//quickSort(a, length);
	//shellSort(a, length);
	heapSort(a, length);
	testPrint(a, length);
	return 0;
}