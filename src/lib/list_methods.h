#ifndef LIST_METHODS_H_
#define LIST_METHODS_H_

#include <iostream>

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

    void push_back(int _val);
    void print();
    void remove_first();
    void remove_last();
    void remove(int _val);

    Node* operator[] (const int index);
    Node* find(int _val);
};

#endif //  LIST_METHODS_H_