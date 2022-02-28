/* Stack.h class*/

#ifndef STACK_H
#define STACK_H
#include "Tree.h"

struct StackNode
{
  Node* data;
  StackNode* next;
};

class Stack
{
 public:
  Stack();
  void push(Node* m);
  Node* peek();
  Node* pop();
  StackNode* head;
};

#endif
