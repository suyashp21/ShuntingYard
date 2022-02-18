/* Stack.h class*/

#ifndef STACK_H
#define STACK_H

struct StackNode
{
  int data;
  StackNode* next;
};

class Stack
{
 public:
  Stack();
  void push(int m);
  int peek();
  int pop();
 private:
  StackNode* head;
};

#endif
