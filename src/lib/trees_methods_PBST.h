#ifndef TREES_METHODS_PBST_H_
#define TREES_METHODS_PBST_H_

#include <iostream>
#include <iomanip>

struct Vertex {
  int data;
  Vertex *left = nullptr;
  Vertex *right = nullptr;
};

int size(Vertex *p);
int height(Vertex *p);
int control_sum(Vertex *p);
int SDP(Vertex *p, int L);
float average_height(Vertex *p);
void print_from_left_to_right(Vertex *p);
void print_from_bottom_to_up(Vertex *p);
void delete_tree(Vertex* p);

#endif //  TREES_METHODS_PBST_H_
