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
    cout << endl;

    string myString = "johnclonnorfgsc";
    cout << "String : " << myString << endl << endl;

    LinkedList *svyazList = pryamSvyaz(myString);
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        if (!svyazList[i].head)
        cout << i << " " << endl;
        else {
        cout << i << " ";
        svyazList[i].print();
        }
    }

    cout << endl << endl;

    cout << "linear" << endl;

    char *list = linear(myString);
    int COL1 = COL_COUNTER;
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        cout << setw(3) << i;
    }
    cout << endl;
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        if (list[i] == 0) {
        cout << setw(3) << " ";
        continue;
        }
        cout << setw(3) << (char)list[i];
    }
    cout << endl << endl << endl;

    cout << "quadra" << endl;

    list = quadra(myString);
    int COL2 = COL_COUNTER;
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        cout << setw(3) << i;
    }
    cout << endl;
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        if (list[i] == 0) {
        cout << setw(3) << " ";
        continue;
        }
        cout << setw(3) << (char)list[i];
    }

    cout << "\n\n\n";

    cout << "Размер хеш-таблицы       Количество исходных символов      "
            "Количество коллизий\n";
    cout << "                                                         Лин.       "
            "Квадр.    \n";
    cout << "   " << HASH_TABLE_SIZE << "                                 " << myString.length()
        << "                   " << COL1 << "          " << COL2 << endl
        << endl
        << endl;

    char toBeFound = 'c';

    cout << "Pryam Svyaz search of " << toBeFound << ": "
        << pryamSvyazSearch(toBeFound, svyazList) << endl;

    list = linear(myString);
    cout << "Linear search of " << toBeFound << ": "
        << linearSearch(toBeFound, list) << endl;

    list = quadra(myString);
    cout << "Quadra search of " << toBeFound << ": "
        << quadraSearch(toBeFound, list) << endl;
    #endif

    #ifdef PBST_M
    int counter = 1;
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
    std::cout << "|";
    print_from_bottom_to_up(root);
    std::cout << "\n";
    std::cout << "                                   " << "From Left To Right" << std::endl;
    std::cout << "|";
    print_from_left_to_right(root);
    std::cout << std::endl;
    std::cout << "Size Of Tree = " << size(root) << std::endl;
    std::cout << "Height Of Tree = " << height(root) << std::endl;
    std::cout << "Average Height Of Tree = " << average_height(root) << std::endl;
    std::cout << "Control Sum = " << control_sum(root) << std::endl;
    delete_tree(root);
    #endif

    return 0;
}
