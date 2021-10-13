#ifndef HASH_METHODS_H_
#define HASH_METHODS_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#define HASH_TABLE_SIZE 11
#define INPUT_STRING_SIZE 25

int COL_COUNTER;

using namespace std;
struct Node {
  char data;
  Node *next;
};

struct LinkedList {
  LinkedList() { head = NULL; }
  ~LinkedList(){};
  void addNode(char val);
  void print();

  Node *head;
};

LinkedList * pryamSvyaz(string str);

int hashFunction(char number);

bool pryamSvyazSearch(char x, LinkedList *table);

bool linearSearch(char x, char *a);

bool quadraSearch(char x, char *a);

char *linear(string str);

char *quadra(string str);

#endif //  HASH_METHODS_H_