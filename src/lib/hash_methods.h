#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

const int hashList = 13;

void print(int *array);
void printHashNum();
void Fill(int *array, int *squareArray, int *lineArray, int arrayLength);
void outPutTable(int hashList, int arrayLength, int lineCollisions, int squareCollisions);

int Hash(int number);
int checkDigitsVal(int number);
int Line(int *array, int *lineArray, int arrayLength);
int Square(int *array, int *squareArray, int arrayLength);
int Search(int *squareArray, int key, int &kol);
