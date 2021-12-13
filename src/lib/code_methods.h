#ifndef CODE_METHODS_H_
#define CODE_METHODS_H_

#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>
#include <stdlib.h>
#include <unordered_map>
#include <fstream>
#include <functional>

void shannon_code(const int n, double p[], int Length[], char c[][20]);
void gilbert_mur_code(const int n, double p[], int Length[], char c[][20]);
void fano_code(int L, int R, int k, double *p, int Length[], char c[][20]);
void huffman_code(int n, double *array, int Length[], char c[][20], double chance[]);
int Med(int L, int R, double *p);

int up(int n, double q, double *array, double chance[]);
void down(int n, int j, int Length[], char c[][20]);

std::unordered_map<char, int> get_char_counts_from_file(const std::string &file_name, int &file_size);
std::vector<std::pair<double, char>> calc_probabilities(const std::unordered_map<char, int> &counter_map, int count);

#endif //  CODE_METHODS_H_
