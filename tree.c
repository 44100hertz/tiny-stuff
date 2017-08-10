#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int sub_num;
    int sub_cap;
    struct node* parent; // next node less deep
    struct node* child;  // next node deeper
    struct node* sib;    // next linked list node
    void (*write)(void* data);
    void* data;
} Node;

void tree_print(Node* n) {
    for(Node* child = n->child; child; child=child->sib) {
        tree_print(child);
    }
    n->write(n->data);
}

Node* add_child(Node* n, Node* new) {
    Node* child = n->child;
    if(!child) {
        n->child = new;
    } else {
        for(; child->sib; child=child->sib);
        child->sib = new;
    }
    return new;
}

void write(void* data) {
    printf(data);
}

Node* Basic_new(char* name) {
    Node* n = calloc(1, sizeof(Node));
    n->write = write;
    n->data = strdup(name);
    return n;
}

int main() {
    Node* n = Basic_new("hello, ");
    add_child(n, Basic_new("world\n"));
    tree_print(n);
    return 0;
}
