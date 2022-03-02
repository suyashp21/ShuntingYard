/*
Tree.h file
This does not have a corresponding .cpp,
but insteads creates a Node struct which is used
by Stack, Queue, and in the main class for
the binary tree. */

#ifndef TREE_H
#define TREE_H

struct Node {
  char data;
  // left and right node pointers for tree
  Node* left;
  Node* right;
};

#endif
