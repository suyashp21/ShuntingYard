/* Queue.h class*/

#ifndef QUEUE_H
#define QUEUE_H
#include "Tree.h"

struct QueueNode
{
  Node* data;
  QueueNode* next;
};

class Queue
{
 public:
  Queue();
  void enqueue(Node* m);
  Node* dequeue();
  QueueNode* head;
};

#endif
