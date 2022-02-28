#include <iostream>
#include "Queue.h"
#include "Tree.h"

using namespace std;

Queue::Queue() {
  head = NULL;
}

void Queue::enqueue(Node* m)
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

Node* Queue::dequeue() {
    QueueNode* n = head;
    Node* k = n->data;
    head = n->next;
    delete n;
    return k;
}
