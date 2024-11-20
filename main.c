#include <stdlib.h>
#include "test/verify_linked_list.h";

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

int main() {
    int values[10] = {1,2,3,4,5,6,7,8,9,10};
    verify_linked_list(values, ARRAY_SIZE(values));
}