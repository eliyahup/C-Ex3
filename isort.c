#include <math.h>
#include <stdio.h>
#define NUM_OF_ARRAY 50

void print_array(int *data, int n) {
	int i;
	for(i = 0; i<n; i++) {
		printf("%d", *data);
		if(i<n-1){
		printf(",");	
		}
		data++;
	}
	printf("\n");
}

void shift_element(int* arr, int i){
	int *arrWithI = arr+i;
	while(i){
		*arrWithI = *(arrWithI-1);
		arrWithI--;
		i--;
	}
}

void insertion_sort(int* arr , int len){
	int i,key,j;
	for (i = 1; i < len; i++) {
		key = *(arr+i);
		j = i-1;
		while (j >= 0 && *(arr+j)> key) { 
            *(arr+j+1) = *(arr+j);
            j--; 
        } 
		 *(arr+j+1) = key; 
	}
}



int main(){
     
	int arr[NUM_OF_ARRAY] = {0};
	for(int i = 0; i< NUM_OF_ARRAY;i++){
		scanf("%d",&*(arr+i));
	 }
	insertion_sort(arr, NUM_OF_ARRAY);
	print_array(arr, NUM_OF_ARRAY);
	return 0;
}
