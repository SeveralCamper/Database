#include "hash_methods.h"

int HashFunction(int num) {
    return num % HASH_TABLE_SIZE;
}

HASH * create_root(int element) {
    HASH *lst;
    lst = new(HASH);
    lst->data = element;
    lst->ptr = NULL;
    return lst;
}

HASH * add_element(hash *lst, int element) {
    HASH *tmp;
    tmp = new HASH;
    lst->ptr = tmp;
    tmp->data = element;
    tmp->ptr = NULL;
    return tmp;
}

char input_string(char * input_string) {
    int string_el = 0;
    while (true) {
        scanf("%c", &input_string[string_el]);
        if (string_el > 24) {
            printf("Max string size is 25 symbols! Your line has been truncated to 25 characters\n");
            break;
        }
        if ((input_string[string_el] >= 'a' && input_string[string_el] <= 'z') ||
        (input_string[string_el] >= 'A' && input_string[string_el] <= 'Z') ||
        (input_string[string_el] == '\n') || ((input_string[string_el] >= '0' && input_string[string_el] <= '9'))) {
            if (input_string[string_el] == '\n') {
                break;
            } else {
                string_el++;
            }
        } else {
            printf("Unvalid input");
            input_string = NULL;
            break;
        }
    }
    return string_el;
}

void input_string_print(char * input_string, int string_length) {
    for (int i = 0; i < string_length; i++) {
        printf("%c", input_string[i]);
    }
}

void list_print(HASH *lst) {

}

int main() {
    char * string = new char[INPUT_STRING_SIZE];
    int string_length = input_string(string);
    printf("%d\n", string_length);
    input_string_print(string, string_length);
}
