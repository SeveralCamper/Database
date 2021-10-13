#include "trees_methods_PBST.h"

int size(Vertex *p) {
  if (!p)
    return 0;
  else {
    return 1 + size(p->left) + size(p->right);
  }
}

int height(Vertex *p) {
  if (!p)
    return 0;
  else {
    return 1 + std::max(height(p->right), height(p->left));
  }
}

int control_sum(Vertex *p) {
  if (!p)
    return 0;
  else {
    return p->data + control_sum(p->left) + control_sum(p->right);
  }
}

int SDP(Vertex *p, int L) {
    
  if (!p)
    return 0;
  else {
    return L + SDP(p->left, L + 1) + SDP(p->right, L + 1);
  }
}

float average_height(Vertex *p) { return float(SDP(p, 1)) / size(p); }

void print_from_left_to_right(Vertex *p) {
  if (p) {
    print_from_left_to_right(p->left);
    std::cout << p->data << std::setw(3) << "|" << std::setw(3);
    print_from_left_to_right(p->right);
  }
}

void print_from_bottom_to_up(Vertex *p) {
  if (p) {
    print_from_bottom_to_up(p->left);
    print_from_bottom_to_up(p->right);
    
    std::cout << p->data << std::setw(3) << "|" << std::setw(3);
    
  }
}

void delete_tree(Vertex* p){
    if(!p) return; else {
        delete_tree(p->left);
        delete_tree(p->right);
        delete p;
    }
}
