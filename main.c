//
// Created by Kensei on 30.11.19.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

struct node *get(struct linkedlist *l, int target) {
    assert(target > 0);
    if (!l) {
        printf("linked-list is empty");
        return NULL;
    }
    struct node *root = l->first;
    if (target == 1) {
        return root;
    }
    if (!root) {
        return NULL;
    }
    struct node *ret = NULL;
    struct node *current = root;
    int idx = 1;
    while (idx < target - 1) {
        current = current->next;
        idx++;
        if (idx == target) {
            ret = current;
            break;
        }
    }
    return ret;
}

int size(struct linkedlist *l) {
    assert(l != NULL);
    int count = 0;
    struct node *current = l->first;
    while(current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}

int main() {
    printf("hello world\n");
    struct linkedlist l = {};

    insert(&l, 3);
    insert(&l, 4);
    insert(&l, 5);
    insert(&l, 2);
    printf("----------------------------\n");

    struct node *current = l.first;
    int count = 0;
    while (current != NULL) {
        count++;
        printf("val is %d\n", current->val);
        struct node *nn = current->next;
        current = nn;
    }

    struct node *target = get(&l, 1);
    if (!target) {
        printf("target is NULL\n");
    } else {
        printf("get node at index %d -> %d\n", 2, target->val);
    }

    int s = size(&l);
    printf("size of list is %d\n", s);
}
