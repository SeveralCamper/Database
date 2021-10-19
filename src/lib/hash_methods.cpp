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

void Fill(int *array, int *squareArray, int *lineArray, int arrayLength) {
  std::cout << "Array Elements: ";
  for (int i = 0; i < arrayLength; i++) {
    array[i] = rand() % 99 + 1;
    if (i + 1 == arrayLength) {
      std::cout << array[i];
    } else {
      std::cout << array[i] << " ";
    }
  }
  for (int i = 0; i < hashList; i++) {
    squareArray[i] = 0; lineArray[i] = 0;
  }
}

int Square(int *array, int *squareArray, int arrayLength) {
  int kol = 0;
  for (int i = 0; i < arrayLength; i++) {
    int j = Hash(array[i]);
    int d = 1;
    while (true) {
      if (squareArray[j] == array[i]) break;
      if (squareArray[j] == 0) { squareArray[j] = array[i]; break;
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

int Line(int *array, int *lineArray, int arrayLength) {
  int kol = 0;
  for (int i = 0; i < arrayLength; i++) {
    int j = Hash(array[i]);
    int z = j;
    while (true) {
      if (lineArray[j] == array[i]) break;
      if (lineArray[j] == 0) {
      lineArray[j] = array[i]; break;
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
int Search(int *squareArray, int key, int &kol) {
  int j = Hash(key);
  int d = 1;
  while (true) {
    if (squareArray[j] == key)
    return j;
    if (squareArray[j] == 0) {
      
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
  std::cout << "| Size H-table | Number Of Elements | Line Collisions | Square Collisions | \n";
  std::cout << "|     " << hashList << "      |         " << arrayLength
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

