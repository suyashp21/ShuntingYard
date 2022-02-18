#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <cstring>
#include <cctype>

using namespace std;

int main() {
  Queue* testing = new Queue();
  testing->enqueue(3);
  testing->enqueue(4);
  testing->enqueue(127);
  int k;
  k = testing->dequeue();
  cout << k;
  k = testing->dequeue();
  cout << k;
  k = testing->dequeue();
  cout << k;
  return 0;
}
