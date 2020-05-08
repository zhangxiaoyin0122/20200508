#include "sort.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	int array[] = { 10,9,8,7,6,5,4,3,2,1 };
	int size = sizeof(array) / sizeof(array[0]);
	//quickSort(array, 0, size - 1);
	quickSortNor(array, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}