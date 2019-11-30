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
    /*
    struct node *last = l->first;
    while (last != NULL) {
        printf("skip\n");
        last = last->next;
    }
    last = (struct node *)malloc(sizeof(struct node));
    *last = nd;

    if (l->first == NULL) {
        printf("l->first is NULL\n");
    } else {
        printf("l->first is not NULL\n");
    }
    */
};

int main() {
    printf("hello world\n");
    struct linkedlist l = {};
    if (l.first == NULL) {
        printf("first is NULL\n");
    } else {
        printf("first is not NULL\n");
    }

    insert(&l, 3);
    printf("----------------------------");

    struct node *current = l.first;
    int count = 0;
    while (current != NULL) {
        printf("hello\n");
        count++;
        printf("val is %d\n", current->val);
        printf("count %d\n", count);
        if (current->next == NULL) {
            printf("current->next == NULL");
            break;
        }
        if (current == NULL) {
            printf("current == NULL");
            break;
        }
        printf("world\n");
        struct node *nn = current->next;
        if (nn == NULL) {
            printf("nn == NULL");
            break;
        }
        current = nn;
    }
}
