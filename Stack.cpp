#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() {
  head = NULL;
}

void Stack::push(int m)
{
  StackNode* n = new StackNode();
  n->next = head;
  n->data = m;
  head = n;
}

int Stack::peek()
{
  if (head != NULL) {
    return head->data;
  }
  else {
    return -1;
  }
}

int Stack::pop()
{
  if (head != NULL) {
    StackNode* n = head;
    int k = n->data;
    head = n->next;
    delete n;
    return k;
  }
  else {
    return -1;
  }
}
