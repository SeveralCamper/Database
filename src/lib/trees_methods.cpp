#include "trees_methods.h"

bool growth;
bool decreasing = false;

int VR, HR;

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

void add_to_SDP_rec(int D, int W, Vertex *&p) {
  if (!p) {
    p = new Vertex;
    p->data = D;
    p->W = W;
    p->left = nullptr;
    p->right = nullptr;
  } else if (D < p->data)
    add_to_SDP_rec(D, W, p->left);
  else if (D > p->data)
    add_to_SDP_rec(D, W, p->right);
}

void del(Vertex*& ql, Vertex*& q) {
	if (ql->right != nullptr) {
		del(ql->right, q);
		if (decreasing)
			BR(ql);
	}
	else {
		//q->data = ql->data;
		q = ql;
		ql = ql->left;
		decreasing = true;
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

void LL1(Vertex *& p) {
	Vertex* q = p->left;
	if (q->balance == 0) {
		q->balance = 1;
		p->balance = -1;
		decreasing = false;
	}
	else {
		q->balance = 0;
		p->balance = 0;
	}
	p->left = q->right;
	q->right = p;
	p = q;
}

void RR1(Vertex *& p) {
	Vertex* q = p->right;
	if (q->balance == 0) {
		q->balance = -1;
		p->balance = 1;
		decreasing = false;
	}
	else {
		q->balance = 0;
		p->balance = 0;
	}
	p->right = q->left;
	q->left = p;
	p = q;
}

void BL(Vertex *& p) { 
	if (p->balance == -1) {
		p->balance = 0;
	}
	else if (p->balance == 0) {
		p->balance = 1;
		decreasing = false;
	}
	else if (p->balance == 1) {
		if (p->right->balance >= 0) {
			RR1(p);
		}
		else {
			RL(p);
		}
	}
}

void BR(Vertex *& p) { 
	if (p->balance == 1) {
		p->balance = 0;
	}
	else if (p->balance == 0) {
		p->balance = -1;
		decreasing = false;
	}
	else if (p->balance == -1) {
		if (p->left->balance <= 0) {
			LL1(p);
		}
		else {
			LR(p);
		}
	}
}

void delete_from_AVL(Vertex*& p, int key) {
	if (p == nullptr);
	else if (p->data > key) {
		delete_from_AVL(p->left, key);
		if (decreasing)
			BL(p);
	}
	else if (p->data < key) {
		delete_from_AVL(p->right, key);
		if (decreasing)
			BR(p);
	}
	else {
		Vertex* q = p;
		if (q->right == nullptr) {
			p = q->left;
			decreasing = true;
		}
		else if (q->left == nullptr) {
			p = q->right;
			decreasing = true;
		}
		else {
			del(q->left, q);
			if (decreasing) 
				BL(p);
		}
		delete q;
	}
}

void B2_insert(int D, Vertex *&p) {
  if (!p) {
    p = new Vertex;
    p->data = D;
    p->left = p->right = NULL;
    p->balance = 0;
    VR = 1;
  } else if (p->data > D) {
    B2_insert(D, p->left);
    if (VR == 1) {
      if (p->balance == 0) {
        Vertex *q = p->left;
        p->left = q->right;
        q->right = p;
        p = q;
        p->balance = 1;
        VR = 0;
        HR = 1;
      } else {
        p->balance = 0;
        VR = 1;
        HR = 0;
      }
    } else
      HR = 0;
  } else if (p->data < D) {
    B2_insert(D, p->right);
    if (VR == 1) {
      p->balance = 1;
      HR = 1;
      VR = 0;
    } else if (HR == 1) {
      if (p->balance == 1) {
        Vertex *q = p->right;
        p->right = q->left;
        p->balance = 0;
        q->balance = 0;
        q->left = p;
        p = q;
        VR = 1;
        HR = 0;
      } else
        HR = 0;
    }
  }
}

void A1(Vertex *&root, int *V1, int *W1, int n) {
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (W1[j] > W1[j + 1]) {
        std::swap(W1[j], W1[j + 1]);
        std::swap(V1[j], V1[j + 1]);
      }
  for (int i = 0; i < n; i++) {
    add_to_SDP_rec(V1[i], W1[i], root);
  }
}

void A2(Vertex *&root, int *V2, int *W2, int L, int R) {
  int weight = 0;
  int sum = 0;
  int i;
  if (L <= R) {
    for (i = L; i < R; i++) {
      weight += W2[i];
    }
    for (i = L; i < R; i++) {
      if ((sum < weight / 2) && (weight + W2[i] > weight / 2))
        break;
      sum += W2[i];
    }
    add_to_SDP_rec(V2[i], W2[i], root);
    A2(root, V2, W2, L, i - 1);
    A2(root, V2, W2, i + 1, R);
  }
}
