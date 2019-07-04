//Created by Brandon Barnes

#include <iostream>

using namespace std;

void heapify(int array[], int size, int index){
	int max = index;
	int l = 2*max+1;
	int r = 2*max+2;
	
	if(l<size&&array[l]>array[max]){
		max = l;
	}
	if(r<size&&array[r]>array[max]){
		max = r;
	}
	if(max != index){
		int temp = array[index];
		array[index] = array[max];
		array[max] = temp;
		
		heapify(array, size, max);
	}
	
}

void buildHeap(int array[], int size){
	int startIndex = (size/2)-1;
	
	for(int i = startIndex; i>(-1);i--){
		heapify(array, size, i);
	}
}

void reverseHeapSort(int array[], int size){
	int temp;
	
	buildHeap(array, size);
	
	for(int i = size-1; i>-1; i--){
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		
		heapify(array, i, 0);
	}
	
}


int main(){
	int array[] = {4, 10, 3, 5, 1};
	
	reverseHeapSort(array, 5);
	for(int i = 0; i<5; i++){
		cout << array[i] << ' ' << endl;
	}
	
	
	
	return 0;
}