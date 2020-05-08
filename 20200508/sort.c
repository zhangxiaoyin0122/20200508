#include "sort.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void Swap(int* array, int begin, int end) {
	int tmp = array[begin];
	array[begin] = array[end];
	array[end] = tmp;
}
int GetMid(int* array, int begin, int end) {
	int mid = begin + (end - begin) / 2;
	if (array[begin] < array[mid]) {
		if (array[mid] < array[end])
			return mid;
		else {
			if (array[begin] > array[end])
				return begin;
			else
				return end;
		}
	}
	else {
		if (array[mid] > array[end])
			return mid;
		else {
			if (array[begin] > array[end])
				return end;
			else
				return begin;
		}
	}
}
int partion(int* array, int begin, int end) {
	int mid = GetMid(array, begin, end);
	Swap(array, begin, mid);
	int prev = begin;
	int cur = prev + 1;
	int key = array[begin];
	while (cur <= end) {
		if (array[cur] < key && ++prev != cur)
			Swap(array, prev, cur);
		cur++;
	}
	Swap(array, begin, prev);
	return prev;
}
void quickSort(int* array, int begin, int end) {
	if (begin >= end)
		return;
	int keypos = partion(array, begin, end);
	quickSort(array, begin, keypos - 1);
	quickSort(array, keypos + 1, end);
}
void quickSortNor(int* array, int n) {
	Queue q;
	QueueInit(&q);
	if (n > 1) {
		QueuePushBack(&q, 0);
		QueuePushBack(&q, n - 1);
	}
	while (QueueEmpty(&q) != 1) {
		int begin = QueueTop(&q);
		QueuePopFront(&q);
		int end = QueueTop(&q);
		QueuePopFront(&q);
		int keypos = partion(array, begin, end);
		if (keypos - 1 > begin) {
			QueuePushBack(&q, begin);
			QueuePushBack(&q, keypos-1);
		}
		if (keypos + 1 < end) {
			QueuePushBack(&q, keypos+1);
			QueuePushBack(&q, end);
		}
	}
}
