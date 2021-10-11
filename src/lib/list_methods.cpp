#include "list_methods.h"

bool List::is_empty() {
    return first == nullptr;
    }

void List::push_back(int _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
        } else {
            last->next = p;
            last = p;
        }
    }

void List::print() {
    if (is_empty()) return;
    Node* p = first;
    while (p) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

Node* List::find(int _val) {
        Node* p = first;
        while (p && p->val != _val) p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

void List::remove_first() {
    if (is_empty()) return;
    Node* p = first;
    first = p->next;
    delete p;
}

void List::remove_last() {
    if (is_empty()) return;
    if (first == last) {
        remove_first();
        return;
    }
    Node* p = first;
    while (p->next != last) p = p->next;
    p->next = nullptr;
    delete last;
    last = p;
}

void List::remove(int _val) {
    if (is_empty()) return;
    if (first->val == _val) {
        remove_first();
        return;
    } else if (last->val == _val) {
        remove_last();
        return;
    } else {
        Node* current_node = first;
        Node* current_node_next = first->next;
        while (current_node_next && current_node_next->val != _val) {
            current_node_next = current_node_next->next;
            current_node = current_node->next;
        }
        if (!current_node_next) {
            std::cout << "This element does not exist" << std::endl;
            return;
        }
        current_node->next = current_node_next->next;
        delete current_node_next;
    }
}

Node* List::operator[] (const int index) {
    if (is_empty()) return nullptr;
    Node* p = first;
    for (int i = 0; i < index; i++) {
        p = p->next;
        if (!p) return nullptr;
    }
    return p;
}

void List::list_tests(List lst, int list_length) {
    int randElAdd = 100;
    char c;
    srand(randElAdd);
    std::cout << "Enter the initial number of items in the list or press ECS to exit" << std::endl;
    if ((scanf("%d%c", &list_length, &c) == 2) && (c == '\n')) {
        for (int i = 0; i < list_length; i++) {
            randElAdd = rand() % 100;
            lst.push_back(randElAdd);
        }
        std::cout << "Entered list" << std::endl;
        lst.print();
        List::cases(lst, list_length);
    } else {
        std::cout << "Unvalid input" << std::endl;
    }
}

void List::cases(List lst, int list_length) {
    std::cout << "Select menu paragraph (1 / 2 / 3 / 4 (quit)):" << std::endl;
    std::cout << "1. Add node" << std::endl;
    std::cout << "2. Remove node" << std::endl;
    std::cout << "3. Output a specific node" << std::endl;
    std::cout << "4. Quit. " << std::endl;
    
    int list_case;
    char c;
    if ((scanf("%d%c", &list_case, &c) == 2) && (c == '\n')) {
        int randElAdd = 100;
        srand(randElAdd);
        switch (list_case) {
            case 1:
                list_case = 0;
                lst.push_back(randElAdd);
                lst.print();
                break;
            case 2:
                list_case = 0;
                lst.remove_last();
                lst.print();
                break;
            case 3:
                std::cout << "What node you ant to output?" << '\n';
                if ((scanf("%d%c", &list_case, &c) == 2) && (c == '\n') && (list_case < list_length)) {
                    std::cout << "Node " << list_case << " is: "<< lst[list_case]->val << std::endl;
                } else {
                    std::cout << "Unvalid input" << '\n';
                }
                break;
            case 4:
                std::cout << "Exit" << '\n';
                break;
            default:
                std::cout << "Unvalid input" << '\n';
                break;
        }
    } else {
        std::cout << "Unvalid input" << std::endl;
    }
}
