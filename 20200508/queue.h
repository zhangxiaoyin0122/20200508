#pragma once

typedef int Type;
typedef struct Node {
	struct Node* _next;
	Type _value;
}Node;

typedef struct Queue {
	Node* _front;
	Node* _rear;
	int _size;
}Queue;
void QueueInit(Queue* q);
Node* creatNode(Type data);
void QueuePushBack(Queue* q, Type data);
void QueuePopFront(Queue* q);
Type QueueTop(Queue* q);
int QueueEmpty(Queue* q);
void QueueDestory(Queue* q);

