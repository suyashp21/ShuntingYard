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
  void enqueue(Node* m); // add a new Node at the end of the queue
  Node* dequeue(); // remove and return a Node from the front
  QueueNode* head;
};

#endif
