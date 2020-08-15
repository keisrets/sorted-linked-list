#include "struct.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

Node * add_node(Node **head, int data);
void print_list(Node **head);
void destroy_list(Node **head);