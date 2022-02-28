#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Tree.h"
#include <cstring>
#include <cctype>

using namespace std;

int prec(char symb);

int main() {
  char expression[100];
  cin.get(expression, 100);
  cin.get();
  Queue* output = new Queue();
  Stack* opstack = new Stack();
  // cout << strlen(expression);

  // translate to postfix notation using shunting yard
  
  for (int i=0; i<strlen(expression); i++) {
    Node* n = new Node();
    n->data = expression[i];
    if (expression[i] == ' ') {
      continue;
    }
    if (expression[i] >= 48 && expression[i] <= 57) {
      output->enqueue(n);
    }
    else if (expression[i] == '(' or expression[i] == '^') {
      opstack->push(n);
    }
    else if (expression[i] == ')') {
      while (opstack->peek()->data != '(') {
	output->enqueue(opstack->pop());
      }
      opstack->pop();
    }
    else if (expression[i] == '+' or expression[i] == '-' or expression[i] == '*' or expression[i] == '/') {
      while (opstack->head != NULL and prec(expression[i]) <= prec(opstack->peek()->data)) {
	output->enqueue(opstack->pop());
      }
      opstack->push(n);
    }
  }

  // queue any remaining operands on stack
  while (opstack->head != NULL) {
    output->enqueue(opstack->pop());
  }

  while (output->head != NULL) {
    Node* k = output->dequeue();
    cout << k->data;
  }

  // TreeStackNode* head = NULL;
  Node* n = new Node();
  n->data = 3;
  // push(n, head);
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

/*
Node* newNode(char symb) {
  Node* n = new Node();
  n->data = symb;
  return n;
}
*/
