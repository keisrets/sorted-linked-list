#include "impl.h"

void run(Node **head) {
    int n = 0;
    scanf("%d", &n);
    while(n > 0) {
        add_node(head, n);
        scanf("%d", &n);
    }
    
    print_list(head);
    destroy_list(head);
}