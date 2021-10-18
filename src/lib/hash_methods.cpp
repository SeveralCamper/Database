#include "hash_methods.h"

int Hash(int number) {
  return number % m;
}

void print(int *a) {
  cout << endl;
  for (int i = 0; i < m; i++) {
    cout << "|" << a[i] << "\t";
  }
  cout << endl;
}

void Fill(int *a, int *b, int *c, int n) {
  cout << "Numbers: ";
  for (int i = 0; i < n; i++) {
    a[i] = rand() % 99 + 1;
    cout << a[i] << " ";
  }
  for (int i = 0; i < m; i++) {
    b[i] = 0; c[i] = 0;
  }
}

int Square(int *a, int *b, int n) {
  int kol = 0;
  for (int i = 0; i < n; i++) {
    int j = Hash(a[i]);
    int d = 1;
    while (true) {
      if (b[j] == a[i]) break;
      if (b[j] == 0) { b[j] = a[i]; break;
    }
    else kol++;
    if (d >= m)
    return kol;
    j += d;
    if (j >= m) j -= m;
    d += 2;
    }
  }
  return kol;
}

int Line(int *a, int *c, int n) {
  int kol = 0;
  for (int i = 0; i < n; i++) {
    int j = Hash(a[i]);
    int z = j;
    while (true) {
      if (c[j] == a[i]) break;
      if (c[j] == 0) {
      c[j] = a[i]; break;
    }
    j++;
    if (z == j)
    return kol;
    if (j >= m) j -= m;
    kol++;
    }
  }
  return kol;
}
int Search(int *b, int key, int &kol) {
  int j = Hash(key);
  int d = 1;
  while (true) {
    if (b[j] == key)
    return j;
    if (b[j] == 0) {
      
    }
    else kol++;
    if (d >= m)
    return -1;
    j += d;
    if (j >= m)
    j -= m;
    d += 2;
  }
}

int checkDigitsVal(int number) {
  int DigitsVal = 0;
  while (number > 0) {
    number = number/10;
    DigitsVal++;
  }
  return DigitsVal;
}