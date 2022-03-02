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
  void push(Node* m); // push a new Node to the class
  Node* peek(); // return at the top Node without removing it
  Node* pop(); // remove the top Node and return it
  StackNode* head;
};

#endif
