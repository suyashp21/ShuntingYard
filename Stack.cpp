#include <iostream>
#include "Stack.h"
#include "Tree.h"

using namespace std;

Stack::Stack() {
  head = NULL;
}

void Stack::push(Node* m)
{
  StackNode* n = new StackNode();
  n->next = head;
  n->data = m;
  head = n;
}

Node* Stack::peek()
{
    return head->data;
}

Node* Stack::pop()
{
    StackNode* n = head;
    Node* k = n->data;
    head = n->next;
    delete n;
    return k;
}
