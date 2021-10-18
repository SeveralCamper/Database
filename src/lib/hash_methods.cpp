#include "hash_methods.h"

int Hash(int number) {
  return number % hashList;
}

void print(int *array) {
  std::cout << std::endl;
  for (int i = 0; i < hashList; i++) {
    if (i + 1 == hashList) {
      std::cout << "|" << array[i] << "|";
    } else {
      std::cout << "|" << array[i] << "|\t";
    }
  }
  std::cout << std::endl;
}

void Fill(int *a, int *b, int *c, int n) {
  std::cout << "Array Elements: ";
  for (int i = 0; i < n; i++) {
    a[i] = rand() % 99 + 1;
    if (i + 1 == n) {
      std::cout << a[i];
    } else {
      std::cout << a[i] << " ";
    }
  }
  for (int i = 0; i < hashList; i++) {
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
    if (d >= hashList)
    return kol;
    j += d;
    if (j >= hashList) j -= hashList;
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
    if (j >= hashList) j -= hashList;
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
    if (d >= hashList)
    return -1;
    j += d;
    if (j >= hashList)
    j -= hashList;
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

void outPutTable(int hashList, int arrayLength, int lineCollisions, int squareCollisions) {
  std::cout << "\n| Size H-table | Number Of Elements | Line Collisions | Square Collisions |\n";
  std::cout << "|     " << hashList << "      |\t " << arrayLength
  << "         |        " << lineCollisions
  << "       |         "<< squareCollisions << "        |";
}

void printHashNum() {
  for (int i = 0; i < hashList; i++) {
    if (i + 1 == hashList) {
        std::cout << "|" << i << "|";
    } else {
      std::cout << "|" << i << "|\t";
    }
  }
}

