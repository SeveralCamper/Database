#include "trees_methods.h"

bool growth;

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

void print_from_up_to_bottom(Vertex *p) {
  if (p) {
    std::cout << p->data << std::setw(3) << "|" << std::setw(3);
    print_from_up_to_bottom(p->left);
    print_from_up_to_bottom(p->right);
  }
}

void delete_tree(Vertex* p){
    if(!p) return; else {
        delete_tree(p->left);
        delete_tree(p->right);
        delete p;
    }
}

Vertex *ISDP(int L, int R, int mas[]) {
  if (L > R)
    return nullptr;
  else {
    int m = (L + R) / 2;
    Vertex *p = new Vertex;
    p->data = mas[m];
    p->left = ISDP(L, m - 1, mas);
    p->right = ISDP(m + 1, R, mas);
    return p;
  } 
}

void add_to_SDP(int D, Vertex *&root) {
    Vertex **p = &root;
    while(*p) {
        if(D < (*p)->data) p = &((*p)->left);
        else if(D > (*p)->data) p = &((*p)->right);
        else break;
    }
    if(!*p) {
        *p = new Vertex;
        (*p)->data = D;
        (*p)->right = nullptr;
        (*p)->left = nullptr;
    }
}

void add_to_SDP_rec(int D, Vertex *&p) {
    if(!p){
        p = new Vertex;
        p->data = D;
        p->left = nullptr;
        p->right = nullptr;
    } else if (D < p->data) {
        add_to_SDP_rec(D, p->left);
    } else if (D > p->data) {
        add_to_SDP_rec(D, p->right);
    } else {
        return;
    }
}


void delete_from_SDP(int key, Vertex *&root) {
    Vertex **p = &root;
    while(*p){
        if((*p)->data < key) p = &((*p)->right);
        else if ((*p)->data > key) p = &((*p)->left);
        else break;
    }
    if(*p){
        Vertex *q = *p;
        if(!q->left) *p = q->right;
        else if (!q->right) *p=q->left;
        else {
            Vertex *r = q->left;
            Vertex *s = q;
            while(r->right){
                s = r;
                r = r->right;
            }
            s->right = r->left;
            r->left = q->left;
            r->right = q->right;
            *p = r;
        }
        delete q;
    }
}

void LL(Vertex *&p) {
  Vertex *q = p->left;
  p->balance = q->balance = 0;
  p->left = q->right;
  q->right = p;
  p = q;
}

void RR(Vertex *&p) {
  Vertex *q = p->right;
  p->balance = q->balance = 0;
  p->right = q->left;
  q->left = p;
  p = q;
}

void LR(Vertex *&p) {
  Vertex *q = p->left;
  Vertex *r = q->right;
  if (r->balance < 0) {
    p->balance = 1;
  } else {
    p->balance = 0;
  }
  if (r->balance > 0) {
    q->balance = -1;
  } else {
    q->balance = 0;
  }
  r->balance = 0;
  q->right = r->left;
  p->left = r->right;
  r->left = q;
  r->right = p;
  p = r;
}

void RL(Vertex *&p) {
  Vertex *q = p->right;
  Vertex *r = q->left;
  if (r->balance > 0) {
    p->balance = -1;
  } else {
    p->balance = 0;
  }
  if (r->balance < 0) {
    q->balance = 1;
  } else {
    q->balance = 0;
  }
  r->balance = 0;
  q->left = r->right;
  p->right = r->left;
  r->right = q;
  r->left = p;
  p = r;
}

void AVL(Vertex *&p, int D) {
  if (!p) {
    p = new Vertex;
    p->data = D;
    p->left = nullptr;
    p->right = nullptr;
    p->balance = 0;
    growth = true;
  } else if (p->data > D) {
    AVL(p->left, D);
    if (growth) {
      if (p->balance > 0) {
        p->balance = 0;
        growth = false;
      } else if (p->balance == 0) {
        p->balance = -1;
        growth = true;
      } else {
        if (p->left->balance < 0) {
          LL(p);
          growth = false;
        } else {
          LR(p);
          growth = false;
        }
      }
    }
  } else if (p->data < D) {
    AVL(p->right, D);
    if (growth) {
      if (p->balance < 0) {
        p->balance = 0;
        growth = false;
      } else if (p->balance == 0) {
        p->balance = 1;
        growth = true;
      } else {
        if (p->right->balance > 0) {
          RR(p);
          growth = false;
        } else {
          RL(p);
          growth = false;
        }
      }
    }
  }
}