#ifndef TREES_METHODS_PBST_H_
#define TREES_METHODS_PBST_H_

#include <algorithm>
#include <iostream>
#include <iomanip>

struct Vertex {
  int data;
  int W = 0;
  int balance = 0;
  Vertex *left = nullptr;
  Vertex *right = nullptr;
};

Vertex *ISDP(int L, int R, int mas[]);

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

void AVL(Vertex *&p, int D);
void RL(Vertex *&p);
void LR(Vertex *&p);
void RR(Vertex *&p);
void LL(Vertex *&p);

void BL (Vertex *&p);
void BR (Vertex *&p);
void LL_1 (Vertex *&p);
void RR_1 (Vertex *&p);
void del(Vertex*& ql, Vertex*& q);
void delete_from_AVL(Vertex*& p, int key);

void B2_insert(int D, Vertex *&p);

void A1(Vertex *&root, int *V1, int *W1, int n);
void A2(Vertex *&root, int *V2, int *W2, int L, int R);

#endif //  TREES_METHODS_PBST_H_
