#ifndef HASH_METHODS_H_
#define HASH_METHODS_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "list_methods.h"
#define HASH_TABLE_SIZE 5
#define INPUT_STRING_SIZE 25

typedef struct hash {
    char data;
    struct hash *ptr;
} HASH;

HASH * create_root(int element);
HASH * add_element(hash *lst, int element);
void list_print(HASH *lst);
int HashFunction(int num);
int input_string(char * input_string, int *string_length);

#endif //  HASH_METHODS_H_