#ifndef TREES_METHODS_PBST_H_
#define TREES_METHODS_PBST_H_

#include <algorithm>
#include <iostream>
#include <iomanip>

struct Vertex {
  int data;
  Vertex *left = nullptr;
  Vertex *right = nullptr;
};

int size(Vertex *p);
int height(Vertex *p);
int SDP(Vertex *p, int L);
int control_sum(Vertex *p);

float average_height(Vertex *p);

void delete_tree(Vertex* p);
void add_to_SDP(int D, Vertex *&root);
void add_to_SDP_rec(int D, Vertex *&p);
void print_from_bottom_to_up(Vertex *p);
void print_from_up_to_bottom(Vertex *p);
void delete_from_SDP(int X, Vertex *&root);
void print_from_left_to_right(Vertex *p);

Vertex *ISDP(int L, int R, int mas[]);

#endif //  TREES_METHODS_PBST_H_
