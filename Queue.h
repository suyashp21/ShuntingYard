/* Queue.h class*/

#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode
{
  int data;
  QueueNode* next;
};

class Queue
{
 public:
  Queue();
  void enqueue(int m);
  int dequeue();
 private:
  QueueNode* head;
};

#endif
