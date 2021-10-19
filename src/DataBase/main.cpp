#include <iostream>
#ifdef LIST_M
#include "../lib/list_methods.h"
#endif
#ifdef HASH_M
#include "../lib/hash_methods.h"
#endif
#ifdef PBST_M
#include "../lib/trees_methods_PBST.h"
#endif

int main()
{
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
    /*int counter = 1;
    std::cout << "Perfectly Balanced Search Tree" << std::endl;
    Vertex *root = new Vertex{counter++};
    root->left = new Vertex{counter++};
    root->right = new Vertex{counter++};
    root->left->left = new Vertex{counter++};
    root->left->right = new Vertex{counter++};
    root->right->left = new Vertex{counter++};
    root->right->right = new Vertex{counter++};
    root->left->left->left = new Vertex{counter++};
    root->left->left->right = new Vertex{counter++};
    root->left->right->left = new Vertex{counter++};
    root->left->right->right = new Vertex{counter++};
    root->right->left->left = new Vertex{counter++};
    root->right->left->right = new Vertex{counter++};
    root->right->right->left = new Vertex{counter++};
    root->right->right->right = new Vertex{counter++};
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
    delete_tree(root);*/

    #ifdef SDP_M

    int mas[100];

    Vertex *rootSDP = nullptr;

      for(int i = 0; i < 100; i++)
      {
        mas[i] = rand() % 100000;
        add_to_SDP(mas[i], rootSDP);
      }

    std::sort(mas, mas + 100);

    Vertex *rootISDP = ISDP(0, 99, mas);

    std::cout << "Perfectly Balanced Search Tree" << std::endl;
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
    std::cout << "\n";

    std::cout << "Size Of Tree = " << size(rootISDP ) << std::endl;
    std::cout << "Height Of Tree = " << height(rootISDP ) << std::endl;
    std::cout << "Average Height Of Tree = " << average_height(rootISDP ) << std::endl;
    std::cout << "Control sum = " << control_sum(rootISDP ) << std::endl;

    std::cout << "\n\n\n\n";
    std::cout << "Random Search Tree" << std::endl;
    std::cout << "                                   " << "From Bottom To Up" << std::endl;
    std::cout << "| ";
    print_from_bottom_to_up(rootSDP);
    std::cout << "\n\n\n\n";
    std::cout << "                                   " << "From Left To Right" << std::endl;
    std::cout << "| ";
    print_from_left_to_right(rootSDP);
    std::cout << "\n\n\n\n";

    std::cout << "|     |   size  |   controlSum  |  height   |  averageHeight|\n";
    std::cout << "|ISDP |   " << size(rootISDP) << "   |    " << control_sum(rootISDP) << "     |    " << height(rootISDP) << "     |       " << average_height(rootISDP) << "     |\n";
    std::cout << "|SDP  |   " << size(rootSDP) << "   |    " << control_sum(rootSDP) << "     |    " << height(rootSDP) << "    |       " << average_height(rootSDP) << "    |\n";
    
    #endif

    #endif

    return 0;
}
