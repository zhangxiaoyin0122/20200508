#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
void QueueInit(Queue* q) {
	q->_front = q->_rear = NULL;
	q->_size = 0;
}
//����ڵ�
Node* creatNode(Type data) {
	Node* node = (Node*)malloc(sizeof(Type));
	node->_value = data;
	node->_next = NULL;
	return node;
}
//�������
void QueuePushBack(Queue* q, Type data) {
	Node* node = creatNode(data);
	if (q->_front==NULL) {
		q->_front = q->_rear = node;
	}
	else {
		q->_rear->_next = node;
		q->_rear = node;//����β�ڵ�
	}
	q->_size++;
}
//���г���
void QueuePopFront(Queue* q) {
	Node* next;
	if (q->_front) {
		next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		if (q->_front == NULL)
			q->_rear = NULL;
	}
	q->_size--;
}
Type QueueTop(Queue* q) {
	return q->_front->_value;
}
int QueueEmpty(Queue* q) {
	if (q->_front == NULL)
		return 1;
	return 0;
}
void QueueDestory(Queue* q) {
	Node* cur = q->_front;
	while (cur) {
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
	q->_size = 0;
}
