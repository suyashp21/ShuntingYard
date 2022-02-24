#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() {
  head = NULL;
}

void Stack::push(char m)
{
  StackNode* n = new StackNode();
  n->next = head;
  n->data = m;
  head = n;
}

char Stack::peek()
{
  if (head != NULL) {
    return head->data;
  }
  else {
    return ' ';
  }
}

char Stack::pop()
{
  if (head != NULL) {
    StackNode* n = head;
    char k = n->data;
    head = n->next;
    delete n;
    return k;
  }
  else {
    return ' ';
  }
}
