#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <cstring>
#include <cctype>

using namespace std;

int prec(char symb);

struct Node {
  int data;
  Node* left;
  Node* right;
};

int main() {
  char expression[100];
  cin.get(expression, 100);
  cin.get();
  Queue* output = new Queue();
  Stack* opstack = new Stack();
  // cout << strlen(expression);
  for (int i=0; i<strlen(expression); i++) {
    if (expression[i] == ' ') {
      continue;
    }
    if (expression[i] >= 48 && expression[i] <= 57) {
      output->enqueue(expression[i]);
    }
    else if (expression[i] == '(' or expression[i] == '^') {
      opstack->push(expression[i]);
    }
    else if (expression[i] == ')') {
      while (opstack->peek() != '(') {
	output->enqueue(opstack->pop());
      }
      opstack->pop();
    }
    else if (expression[i] == '+' or expression[i] == '-' or expression[i] == '*' or expression[i] == '/') {
      while (opstack->peek() != ' ' and prec(expression[i]) <= prec(opstack->peek())) {
	output->enqueue(opstack->pop());
      }
      opstack->push(expression[i]);
    }
  }
  while (opstack->peek() != ' ') {
    output->enqueue(opstack->pop());
  }
  for (int i=0; i<20; i++) {
    cout << output->dequeue();
  }
  return 0;
}

int prec(char symb) {
  if (symb == '^') {
    return 4;
  }
  else if (symb == '*' or symb == '/') {
    return 3;
  }
  else if (symb == '+' or symb == '-') {
    return 2;
  }
  else {
    return 0;
  }
}
