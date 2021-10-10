#ifndef LIST_METHODS_H_
#define LIST_METHODS_H_

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;
  Node* next;
  Node(int _val) : val(_val), next(nullptr){}
};

struct List {
    Node* first;
    Node* last;

    List() : first(nullptr), last(nullptr) {}

    bool is_empty();

    void list_tests(List stl, int list_length);
    void cases(List lst, int list_length);
    void push_back(int _val);
    void print();
    void remove_first();
    void remove_last();
    void remove(int _val);

    Node* operator[] (const int index);
    Node* find(int _val);
};

#endif //  LIST_METHODS_H_