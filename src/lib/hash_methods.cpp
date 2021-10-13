#include "hash_methods.h"

int hashFunction(char number) {
    return number % HASH_TABLE_SIZE;
}

void LinkedList::addNode(char val) {
  Node *newnode = new Node();
  newnode->data = val;
  newnode->next = NULL;
  if (head == NULL) {
    head = newnode;
  } else {
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newnode;
  }
}

void LinkedList::print() {
  if (head == NULL) {
    return;
  } else {
    Node *temp = head;
    while (temp) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << endl;
  }
}

bool pryamSvyazSearch(char x, LinkedList *table) {
  Node *head = table[hashFunction(x)].head;
  if (head == NULL) {
    return false;
  }
  Node *temp = head;
  while (temp) {
    if (temp->data == x) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

LinkedList *pryamSvyaz(string str) {
  LinkedList *list = new LinkedList[HASH_TABLE_SIZE];
  for (auto chr : str) {
    unsigned int h = hashFunction(chr);
    if (!pryamSvyazSearch(chr, list))
      list[h].addNode(chr);
  }
  return list;
}

bool linearSearch(char x, char *a) {
  auto h = hashFunction(x);
  while (true) {
    if (a[h] == x) {
      return true;
    }
    if (a[h] == 0) {
      return false;
    };
    h++;
    if (h >= HASH_TABLE_SIZE) {
      h -= HASH_TABLE_SIZE;
    };
  }
}

bool quadraSearch(char x, char *a) {
  auto h = hashFunction(x);
  int d = 1;
  while (true) {
    if (a[h] == x) {
      return true;
    }
    if (a[h] == 0) {
      return false;
    };
    h += d;
    if (h >= HASH_TABLE_SIZE)
      h -= HASH_TABLE_SIZE;
    d += 2;
  }
}

char *linear(string str) {
  COL_COUNTER = 0;
  char *a = new char[HASH_TABLE_SIZE];
  for (int i = 0; i < HASH_TABLE_SIZE; i++) {
    a[i] = 0;
  }
  for (auto x : str) {
    bool counterFlag = false;
    auto h = hashFunction(x);
    int d = h;
    bool COL_COUNTER_CHECK = true;
    while (true) {
      if (a[h] == x) {
        break;
      }
      if (a[h] == 0) {
        a[h] = x;
        break;
      };
      if (d == h - 1 && counterFlag) {
        cerr << "ПЕРЕПОЛНЕНИЕ";
        return NULL;
      };
      if (COL_COUNTER_CHECK)
        COL_COUNTER++;
      COL_COUNTER_CHECK = false;
      h++;
      if (h >= HASH_TABLE_SIZE) {
        h -= HASH_TABLE_SIZE;
        counterFlag = true;
      };
    }
  }
  return a;
}

char *quadra(string str) {
  COL_COUNTER = 0;
  char *a = new char[HASH_TABLE_SIZE];
  for (int i = 0; i < HASH_TABLE_SIZE; i++) {
    a[i] = 0;
  }
  for (auto x : str) {
    auto h = hashFunction(x);
    int d = 1;
    bool COL_COUNTER_CHECK = true;
    while (true) {
      if (a[h] == x) {
        break;
      }
      if (a[h] == 0) {
        a[h] = x;
        break;
      };
      if (d >= HASH_TABLE_SIZE) {
        cerr << "ПЕРЕПОЛНЕНИЕ";
        return NULL;
      };

      if (COL_COUNTER_CHECK)
        COL_COUNTER++;
      COL_COUNTER_CHECK = false;

      h += d;
      if (h >= HASH_TABLE_SIZE)
        h -= HASH_TABLE_SIZE;
      d += 2;
    }
  }
  return a;
}
