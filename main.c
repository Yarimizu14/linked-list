//
// Created by Kensei on 30.11.19.
//
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
} node1;

struct linkedlist {
    struct node *first;
};

void insert(struct linkedlist *l, int n) {
    struct node nd = {n};
    if (l->first == NULL) {
        l->first = (struct node *)malloc(sizeof(struct node));
        *l->first = nd;
        return;
    }
    struct node *last = l->first;
    while (last->next != NULL) {
        printf("skip\n");
        last = last->next;
    }
    printf("last node is %d\n", last->val);
    last->next = (struct node *)malloc(sizeof(struct node));
    *last->next = nd;
};

int main() {
    printf("hello world\n");
    struct linkedlist l = {};

    insert(&l, 3);
    insert(&l, 4);
    insert(&l, 5);
    printf("----------------------------\n");

    struct node *current = l.first;
    int count = 0;
    while (current != NULL) {
        count++;
        printf("val is %d\n", current->val);
        struct node *nn = current->next;
        current = nn;
    }
}
