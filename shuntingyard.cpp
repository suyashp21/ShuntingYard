/*
Author: Suyash Pandit
Date: March 2, 2022
This program uses the Shunting Yard algorithm
to build a binary expression tree for mathematical expressions.
The user can choose between infix, prefix, or postfix output. */

#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Tree.h"
#include <cstring>
#include <cctype>

using namespace std;

int prec(char symb);
void postfix(Node* n);
void prefix(Node* n);

int main() {
  char expression[100];
  char printout[10];
  cout << "Enter your expression below:" << endl;
  cin.get(expression, 100);
  cin.get();
  cout << "infix, prefix, or postfix? (all lowercase)" << endl;
  cin.get(printout, 10);
  cin.get();
  Queue* output = new Queue();
  Stack* opstack = new Stack();
  Stack* treestack = new Stack();
  // cout << strlen(expression);

  // translate to postfix notation using shunting yard
  
  for (int i=0; i<strlen(expression); i++) {
    Node* n = new Node();
    n->data = expression[i];
    if (expression[i] == ' ') {
      // ignore spaces
      continue;
    }
    if (expression[i] >= 48 && expression[i] <= 57) { // digit
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

  // make the binary tree

  while (output->head != NULL) {
    Node* k = output->dequeue();
    if (k->data >= 48 && k->data <=57) {
      treestack->push(k);
    }
    else {
      k->right = treestack->pop();
      k->left = treestack->pop();
      treestack->push(k);
    }
  }

  /* while (output->head != NULL) {
    Node* k = output->dequeue();
    cout << k->data;
    } */

  Node* tree = treestack->pop();

  if (strcmp(printout, "infix") == 0) {
    cout << expression;
  }
  if (strcmp(printout, "postfix") == 0) {
    postfix(tree);
  }
  if (strcmp(printout, "prefix") == 0) {
    prefix(tree);
  }


  return 0;
}

int prec(char symb) {

  // determine precedence of an operand
  
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

void postfix(Node* n) {
  // use recursion to output postfix notation
  if (n->left != NULL && n->right != NULL) {
    postfix(n->left);
    postfix(n->right);
  }
  // print out AFTER recursion
  cout << n->data;
}

void prefix(Node* n) {
  // use recursion to output prefix notation
  // print out BEFORE recursion
  cout << n->data;
  if (n->left != NULL && n->right != NULL) {
    prefix(n->left);
    prefix(n->right);
  }
}

/*
Node* newNode(char symb) {
  Node* n = new Node();
  n->data = symb;
  return n;
}
*/
