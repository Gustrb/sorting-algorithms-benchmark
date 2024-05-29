#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define BUCKET_COUNT 10

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Bucket;

void insert_sorted(Node **head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        new_node->next = *head;
        *head = new_node;
    } else {
        Node *current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void bucket_sort(int *array, size_t size) {
    if (size <= 1) return;

    // Create buckets
    Bucket buckets[BUCKET_COUNT];
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i].head = NULL;
        buckets[i].tail = NULL;
    }

    // Determine the range of the elements
    int min_value = array[0];
    int max_value = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] < min_value) min_value = array[i];
        if (array[i] > max_value) max_value = array[i];
    }
    int range = max_value - min_value + 1;

    // Distribute elements into buckets
    for (size_t i = 0; i < size; i++) {
        int bucket_index = (array[i] - min_value) * BUCKET_COUNT / range;
        if (bucket_index >= BUCKET_COUNT) bucket_index = BUCKET_COUNT - 1;
        insert_sorted(&buckets[bucket_index].head, array[i]);
    }

    // Concatenate buckets back into array
    size_t index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        Node *current = buckets[i].head;
        while (current != NULL) {
            array[index++] = current->data;
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}
