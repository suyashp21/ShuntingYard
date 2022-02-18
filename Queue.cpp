#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() {
  head = NULL;
}

void Queue::enqueue(int m)
{
  QueueNode* n = new QueueNode();
  n->data = m;
  if (head == NULL) {
    head = n;
  }
  else {
    QueueNode* n2 = head;
    while (n2->next != NULL) {
      n2 = n2->next;
    }
    n2->next = n;
  }
}

int Queue::dequeue() {
  if (head == NULL) {
    return -1;
  }
  else {
    QueueNode* n = head;
    int k = n->data;
    head = n->next;
    delete n;
    return k;
  }
}
