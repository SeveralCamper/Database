#include <iostream>
#include <iomanip>
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
    int n, key, kol = 0;
    cout << "Enter n: ";
    cin >> n;
    int a[n], b[m], c[m];
    Fill(a, b, c, n);
    int x = Square(a, b, n);
    int y = Line(a, c, n);
    cout << "\nSquare\n";
    for (int i = 0; i < m; i++) {
    cout << "|" << i << "\t";
    }
    print(b);
    cout << "\nLine\n";
    for (int i = 0; i < m; i++) {
    cout << "|" << i << "\t";
    }

    print(c);
    cout << "\n| Size  H-table | number of elements | Line collisions | Square collisions |\n";
    cout << "|" << std::setw(7) << m << std::setw(7) << "|"
    << std::setw(9) << n << std::setw(9) << "|"
    << std::setw(8) << y << std::setw(8) << "|"
    << std::setw(9) << x << std::setw(9) << "|";
    cout << "\nEnter key for search: ";
    cin >> key;
    if (Search(b, key, kol) == -1) {
    cout << "Search: Not found; collisions = " << kol;
    } else {
        cout << "Search: index = " << Search(b, key, kol) << "; collisions = " << kol; return 0;
    }

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
