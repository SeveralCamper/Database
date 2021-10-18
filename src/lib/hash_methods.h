#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

const int hashList = 13;

void print(int *a);
void printHashNum();
void Fill(int *a, int *b, int *c, int n);
void outPutTable(int hashList, int arrayLength, int y, int x);

int Hash(int number);
int checkDigitsVal(int number);
int Line(int *a, int *c, int n);
int Square(int *a, int *b, int n);
int Search(int *b, int key, int &kol);
