#include <iostream>
#ifdef LIST_M
#include "../lib/list_methods.h"
#endif
#ifdef HASH_M
#include "../lib/hash_methods.h"
#endif
#include "../lib/trees_methods.h"
#ifdef CODE_M
#include "../lib/code_methods.h"
#endif

const int n = 100;
int AW[n][n];
int AP[n][n];
int AR[n][n];
int W[n];
int V[n];

void calculate_AW();
void calculate_AP_AR();
void add_to_DOP(int D, int W, Vertex *&p);
void create_tree(int L, int R, Vertex *&root);

int main() {
  #ifdef LIST_M
  List lst;
  int list_length = 0;
  lst.list_tests(lst, list_length);
  return 0;
  #endif

  #ifdef HASH_M
  srand(time(nullptr));
  int arrayLength, key, kolision = 0;
  std::cout << "Enter array length: ";
  std::cin >> arrayLength;
  int array[arrayLength], squareArray[hashList], lineArray[hashList];
  Fill(array, squareArray, lineArray, arrayLength);
  int squareCollisions = Square(array, squareArray, arrayLength);
  int lineCollisions = Line(array, lineArray, arrayLength);
  std::cout << "\nSquare\n";
  printHashNum();
  print(squareArray);
  std::cout << "\nLine\n";
  printHashNum();

  print(lineArray);
  outPutTable(arrayLength,hashList, lineCollisions, squareCollisions);
    
  std::cout << "\nEnter key for search: ";
  std::cin >> key;
  std::cout << std::endl;
  if (Search(squareArray, key, kolision) == -1) {
  std::cout << "Search: Not found" << std::endl;
  } else {
    std::cout << "Search: index = " << Search(lineArray, key, kolision) << "; collisions = " << kolision; return 0;
  }
  #endif

  #ifdef PBST_M
  std::cout << "Perfectly Balanced Search Tree" << std::endl;
  int arr[100];
  for (int i = 0; i < 100; i++) {
    arr[i] = rand() % 5000;
  }
  std::sort(arr, arr + 100);

  Vertex *root = ISDP(0, 99, arr);

  std::cout << "                                   " << "From Bottom To Up" << std::endl;
  std::cout << "| ";
  print_from_bottom_to_up(root);
  std::cout << "\n";
  std::cout << "                                   " << "From Left To Right" << std::endl;
  std::cout << "| ";
  print_from_left_to_right(root);
  std::cout << std::endl;
  std::cout << "Size Of Tree = " << size(root) << std::endl;
  std::cout << "Height Of Tree = " << height(root) << std::endl;
  std::cout << "Average Height Of Tree = " << average_height(root) << std::endl;
  std::cout << "Control Sum = " << control_sum(root) << std::endl;
  delete_tree(root);

  #endif

  #ifdef SDP_M
  std::cout << "Random Search Tree" << std::endl;

  int mas[100];

  Vertex *rootSDP = nullptr;

  for(int i = 0; i < 100; i++) {
    mas[i] = rand() % 100000;
    add_to_SDP(mas[i], rootSDP);
  }

  std::sort(mas, mas + 100);

  Vertex *rootISDP = ISDP(0, 99, mas);

  std::cout << "\n\n\n\n";
  std::cout << "                                   " << "From Bottom To Up" << std::endl;
  std::cout << "| ";
  print_from_bottom_to_up(rootISDP );
  std::cout << "\n\n\n\n";
  std::cout << "                                   " << "From Left To Right" << std::endl;
  std::cout << "| ";
  print_from_left_to_right(rootISDP );
  std::cout << "\n\n\n\n";
  std::cout << "                                   " << "From Up To Bottom" << std::endl;
  std::cout << "| ";
  print_from_up_to_bottom(rootISDP );

  std::cout << "Size Of Tree = " << size(rootISDP ) << std::endl;
  std::cout << "Height Of Tree = " << height(rootISDP ) << std::endl;
  std::cout << "Average Height Of Tree = " << average_height(rootISDP ) << std::endl;
  std::cout << "Control sum = " << control_sum(rootISDP ) << std::endl;

  std::cout << "\n\n\n\n";
  std::cout << "                                   " << "From Bottom To Up" << std::endl;
  std::cout << "| ";
  print_from_bottom_to_up(rootSDP);
  std::cout << "\n\n\n\n";
  std::cout << "                                   " << "From Left To Right" << std::endl;
  std::cout << "| ";
  print_from_left_to_right(rootSDP);
  std::cout << "\n\n\n\n";

  std::cout << "|     |   Size  |   ControlSum  |  Height   |  AverageHeight|\n";
  std::cout << "|ISDP |   " << size(rootISDP) << "   |    " << control_sum(rootISDP) << "    |     " << height(rootISDP) << "     |       " << average_height(rootISDP) << "     |\n";
  std::cout << "|SDP  |   " << size(rootSDP) << "   |    " << control_sum(rootSDP) << "    |     " << height(rootSDP) << "    |       " << average_height(rootSDP) << "    |\n";
    
  return 0;

  #endif

  #ifdef DELSDP_M

  std::cout << "Random Search Tree" << std::endl;

  int mas[10];

  Vertex *rootSDP = nullptr;

  for(int i = 0; i < 10; i++) {
    mas[i] = rand() % 100;
    add_to_SDP(mas[i], rootSDP);
  }

  std::cout << "                                   " << "From Left To Right" << std::endl;
  std::cout << "| ";
  print_from_left_to_right(rootSDP);
  std::cout << "\n\n\n\n";

  for(int i  = 0; i < 3; i++) {
    int key;
    std::cin >> key;
    delete_from_SDP(key, rootSDP);
  }

  std::cout << "                                   " << "From Left To Right" << std::endl;
  std::cout << "| ";
  print_from_left_to_right(rootSDP);
  std::cout << "\n\n\n\n";
  
  #endif

  #ifdef AVL_M

  srand(time(NULL));
  Vertex *rootAVL = nullptr;
  Vertex *rootSDP = nullptr;
  int mas[100];

  for (int i = 0; i < 100; i++) {
    mas[i] = rand() % 1000000;
  }
    
  for (int i = 0; i < 100; i++) {
    AVL(rootAVL, mas[i]);
    add_to_SDP(mas[i], rootSDP);
  }

  std::cout << "|     |   Size  |   ControlSum  |  Height   |  AverageHeight|\n";
  std::cout << "|AVL  |   " << size(rootAVL) << "   |    " << control_sum(rootAVL) << "   |     " << height(rootAVL) << "     |       " << average_height(rootAVL) << "    |\n";
  std::cout << "|SDP  |   " << size(rootSDP) << "   |    " << control_sum(rootSDP) << "   |     " << height(rootSDP) << "    |       " << average_height(rootSDP) << "    |\n";

  #endif

  #ifdef AVL_DEL_M
  srand(time(NULL));
  Vertex *rootAVL = nullptr;
  for(int i = 0; i < 15; i++) {
	  AVL(rootAVL, rand() % 1000 + 1);
  }
  std::cout << "|";
  print_from_left_to_right(rootAVL);
  for(int i = 0; i < 10; i++) {
    std::cout << "\n";
    int key;
    std::cin >> key;
    delete_from_AVL(rootAVL, key);
    std::cout << "|";
    print_from_left_to_right(rootAVL);
    }
    #endif

  #ifdef DBD_M

  srand(time(NULL));
  Vertex *rootAVL = nullptr;
  Vertex *rootDBD = nullptr;
  for (int i = 0; i < 100; i++) {
    int value = rand() % 1000000;
    AVL(rootAVL, value);
    B2_insert(value, rootDBD);
  }
  std::cout << "|";
  print_from_left_to_right(rootDBD);

  std::cout << "\n\n\n\n";

  std::cout << "|     |   Size  |   ControlSum  |  Height   |  AverageHeight|\n";
  std::cout << "|AVL  |   " << size(rootAVL) << "   |    " << control_sum(rootAVL) << "   |     " << height(rootAVL) << "     |       " << average_height(rootAVL) << "    |\n";
  std::cout << "|DBD  |   " << size(rootDBD) << "   |    " << control_sum(rootDBD) << "   |     " << height(rootDBD) << "     |       " << average_height(rootDBD) << "    |\n";

  #endif

  #ifdef DOP_M
  
  srand(time(NULL));

  Vertex *DOP_Tree = nullptr;
  for (int i = 0; i <= n; i++) {
    V[i] = rand() % (n * 1000);
    W[i] = rand() % (n / 4);
  };

  calculate_AW();
  calculate_AP_AR();
  create_tree(0, n, DOP_Tree);
  std::cout << "|";
  print_from_left_to_right(DOP_Tree);
  
  std::cout << "\n\n\n\n";
  
  std::cout << "|     |   Size  |   ControlSum  |  Height   |  AverageHeight|\n";
  std::cout << "|DOP  |   " << size(DOP_Tree) << "   |    " << control_sum(DOP_Tree) << "    |     " << height(DOP_Tree) << "    |      " << average_height(DOP_Tree) << "     |\n";
  
  #endif

  #ifdef A1_A2_M
  srand(time(NULL));
  int len = 100;
  int V_A1_A2[len], W_A1_A2[len], V1_A1_A2[len], W1_A1_A2[len];
  Vertex *A1tree = nullptr;
  Vertex *A2tree = nullptr;
  int V_values;
	int W_valuse;
  for (int i = 0; i < len; i++) {
    V_values = rand() % (len * 1000);
    W_valuse =  rand() % (len / 4);
    V1_A1_A2[i] = V_values;  V_A1_A2[i]  = V_values;
    W1_A1_A2[i] = W_valuse;  W_A1_A2[i]  = W_valuse;
  };

  A1(A1tree, V_A1_A2, W_A1_A2, len);
  A2(A2tree, V1_A1_A2, W1_A1_A2, 0, len-1);

	print_from_left_to_right(A1tree);
 std::cout << "\n\n\n\n";

 print_from_left_to_right(A2tree);
 std::cout << "\n\n\n\n";
	
  std::cout << "|     |   Size  |   ControlSum  |  Height   |  AverageHeight|\n";
  std::cout << "|A1   |   " << size(A1tree) << "   |    " << control_sum(A1tree) << "    |     " << height(A1tree) << "    |      " << average_height(A1tree) << "     |\n";
  std::cout << "|A2   |   " << size(A2tree) << "   |    " << control_sum(A2tree) << "    |     " << height(A2tree) << "    |      " << average_height(A2tree) << "     |\n";

  #endif

  #ifdef CODE_M
	double entropy;
	double average_Shannon, average_Fano, average_Gilbert, average_Haffman;
  int file_size;
  std::unordered_map<char, int> counter_map;

  std::cout << "Entropy table of symbols" << std::endl;

  try {
      counter_map = get_char_counts_from_file("misc/file.txt", file_size);
  } catch (std::runtime_error &exc) {
      std::cout << exc.what();
      return 1;
  }
  auto probabilities = calc_probabilities(counter_map, file_size);
  counter_map.clear();

  std::sort(probabilities.begin(), probabilities.end(), std::greater<std::pair<double, char>>());
  for (auto i : probabilities) {
      std::cout << std::fixed << i.first << " | " << i.second << '\n';
  }

  const int n = (int) probabilities.size();

  auto c = new char[n][20];
  auto Length = new int[n];
  auto p = new double[n];
  for (int i = 0; i < n; ++i) {
      p[i] = probabilities[i].first;
  entropy += p[i] * log2(p[i]);
  }
  double chance_l[n];

  char encMode = 0;
  while (encMode != '0') {
    std::cout << "\n";
    std::cout << "Enter Encoding Mode" << std::endl;
    std::cout << "\n";
    std::cout << "1 - Shannon Code" << std::endl;
    std::cout << "2 - Gilbert-Mur Code" << std::endl;
    std::cout << "3 - Fano Code" << std::endl;
    std::cout << "4 - Haffman Code" << std::endl;
    std::cout << "5 - Average Length Table" << std::endl;
    std::cout << "0 - Exit" << std::endl;
    std::cin >> encMode;
      switch (encMode) {
        case '0':
          break;
        case '1': {
          shannon_code(n, p, Length, c);
          std::cout << "\nShannon Code:\n";
          std::cout << "\nQ Length Code\n";
          for (int i = 0; i < n; i++) {
              printf("%c | %.5lf %d ", probabilities[i].second, p[i], Length[i]);
          average_Shannon += p[i] * Length[i];
              for (int j = 0; j < Length[i]; ++j) {
                  printf("%c", c[i][j]);
              }
              std::cout << '\n';
          }
          average_Shannon = average_Fano = average_Haffman = average_Gilbert = 0;
          break;
        }
        case '2': {
          gilbert_mur_code(n, p, Length, c);
          std::cout << "\nGilbert-Mur Code:\n";
          std::cout << "\nQ Length Code\n";
          for (int i = 0; i < n; i++) {
              printf("%c | %.5lf %d ", probabilities[i].second, p[i], Length[i]);
          average_Gilbert += p[i] * Length[i];
              for (int j = 0; j < Length[i]; ++j) {
                  printf("%c", c[i][j]);
              }
              std::cout << '\n'; 
          }
          average_Shannon = average_Fano = average_Haffman = average_Gilbert = 0;
          break;
        }
        case '3': {
          for (int i = 0; i < n; ++i) {
              Length[i] = 0;
          }
          fano_code(0, n - 1, -1, p, Length, c);
          std::cout << "\nFano Code:\n";
          std::cout << "\nQ Length Code\n";
          for (int i = 0; i < n; i++) {
              printf("%c | %.5lf %d ", probabilities[i].second, p[i], Length[i]);
          average_Fano += p[i] * Length[i];
              for (int j = 0; j < Length[i]; ++j) {
                  printf("%c", c[i][j]);
              }
              std::cout << '\n';
          }
          average_Shannon = average_Fano = average_Haffman = average_Gilbert = 0;
          break;
        }
        case '4': {
          for (int i = 0; i < n; ++i) {
              Length[i] = 0;
              chance_l[i] = p[i];
          }
          huffman_code(n, chance_l, Length, c, p);
          std::cout << "\nHaffman Code:\n";
          std::cout << "\nQ Length Code\n";
          for (int i = 0; i < n; i++) {
              printf("%c | %.5lf %d ", probabilities[i].second, p[i], Length[i]);
          average_Haffman += p[i] * Length[i];
              for (int j = 0; j < Length[i]; ++j) {
                  printf("%c", c[i][j]);
              }
              std::cout << '\n';
          }
          average_Shannon = average_Fano = average_Haffman = average_Gilbert = 0;
          break;
        }
        case '5': {
          shannon_code(n, p, Length, c);
          for (int i = 0; i < n; i++) {
          average_Shannon += p[i] * Length[i];
          }

          gilbert_mur_code(n, p, Length, c);
          for (int i = 0; i < n; i++) {
          average_Gilbert += p[i] * Length[i];
          }

          for (int i = 0; i < n; ++i) {
              Length[i] = 0;
          }
          fano_code(0, n - 1, -1, p, Length, c);
          for (int i = 0; i < n; i++) {
          average_Fano += p[i] * Length[i];
          }

          for (int i = 0; i < n; ++i) {
              Length[i] = 0;
              chance_l[i] = p[i];
          }
          huffman_code(n, chance_l, Length, c, p);
          for (int i = 0; i < n; i++) {
          average_Haffman += p[i] * Length[i];
          }

        	std::cout << "\n\nEntropy = " << -entropy << std::endl;
          std::cout << "Haffman Average Length = " << average_Haffman  << std::endl;
          std::cout << "Fano Average Length = " << average_Fano << std::endl;
          std::cout << "Shannon Average Length = " << average_Shannon  << std::endl;
          std::cout << "Gilbert Moore AverageLength = " << average_Gilbert << std::endl;
          average_Shannon = average_Fano = average_Haffman = average_Gilbert = 0;
          break;
        }
        default: {
          break;
        }
    }
  }
  delete[] p;
  #endif
}

  void calculate_AW() {
    for (int i = 0; i <= n; i++)
      for (int j = i + 1; j <= n; j++) 
        AW[i][j] = AW[i][j - 1] + W[j];
  }

  void calculate_AP_AR() {
    int i, j, m, min, k, h;
    for (i = 0; i <= n - 1; i++) {
      j = i + 1;
      AP[i][j] = AW[i][j];
      AR[i][j] = j;
    }
    for (h = 2; h <= n; h++) {
      for (i = 0; i <= n - h; i++) {
        j = i + h;
        m = AR[i][j - 1];
        min = AP[i][m - 1] + AP[m][j];
        for (k = m + 1; k <= AR[i + 1][j]; k++) {
          int x = AP[i][k - 1] + AP[k][j];
          if (x < min) {
            m = k;
            min = x;
          }
        }
        AP[i][j] = min + AW[i][j];
        AR[i][j] = m;
      }
    }
  }
  
  void add_to_DOP(int D, int W, Vertex *&p) {
    if (!p) {
      p = new Vertex;
      p->data = D;
      p->W = W;
      p->left = nullptr;
      p->right = nullptr;
    } else if (D < p->data)
      add_to_DOP(D, W, p->left);
    else if (D > p->data)
      add_to_DOP(D, W, p->right);
  }

  void create_tree(int L, int R, Vertex *&root) {
    if (L < R) {
      int k = AR[L][R];
      add_to_DOP(V[k], W[k], root);
      create_tree(L, k - 1, root);
      create_tree(k, R, root);
    }
  }
