#include <iostream>
#ifdef LIST_M
#include "../lib/list_methods.h"
#endif
#ifdef HASH_M
#include "../lib/hash_methods.h"
#endif
#include "../lib/trees_methods.h"

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

    #ifdef B2_INSERT_M

  srand(time(NULL));
  Vertex *rootAVL = nullptr;
  Vertex *rootBDB = nullptr;
  for (int i = 0; i < 100; i++) {
    int value = rand() % 1000000;
    AVL(rootAVL, value);
    B2_insert(value, rootBDB);
  }
  std::cout << "|";
  print_from_left_to_right(rootBDB);
  std::cout << "\n\n\n\n\n\n\n";
std::cout << "|     |   Size  |   ControlSum  |  Height   |  AverageHeight|\n";
  std::cout << "|AVL  |   " << size(rootAVL) << "   |    " << control_sum(rootAVL) << "   |     " << height(rootAVL) << "     |       " << average_height(rootAVL) << "    |\n";
  std::cout << "|DBD  |   " << size(rootBDB) << "   |    " << control_sum(rootBDB) << "   |     " << height(rootBDB) << "     |       " << average_height(rootBDB) << "    |\n";

    #endif
}
