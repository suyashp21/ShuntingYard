/* Stack.h class*/

#ifndef STACK_H
#define STACK_H

struct StackNode
{
  char data;
  StackNode* next;
};

class Stack
{
 public:
  Stack();
  void push(char m);
  char peek();
  char pop();
 private:
  StackNode* head;
};

#endif
