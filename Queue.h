/* Queue.h class*/

#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode
{
  char data;
  QueueNode* next;
};

class Queue
{
 public:
  Queue();
  void enqueue(char m);
  char dequeue();
 private:
  QueueNode* head;
};

#endif
