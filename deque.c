#include "deque.h"

#include <stdio.h>
#include <stdlib.h>

// create/destroy functions
Deque* dq_create(int capacity) {
    // allocate memory for the deque struct
    Deque* deque = malloc(sizeof(Deque));

    // check if memory was allocated properly
    if (!deque) return NULL;

    // allocate memory for the deque storage
    deque->arr = malloc(sizeof(void*) * capacity);

    // check if memory was allocated properly
    if (!deque->arr) { free(deque); return NULL; }

    // set the properties of the deque
    deque->capacity = capacity;
    dq_clear(deque);
    return deque;
}

void dq_clear(Deque* deque) {
    deque->left = 0; deque->right = 0;
    for (int i = 0; i < deque->capacity; i++)
        deque->arr[i] = NULL;
}

void dq_free(Deque* deque) {
    dq_clear(deque);
    free(deque->arr);
    free(deque);
}

// operations for the right side
void dq_append(Deque* deque, void* value) {
    if (dq_full(deque)) return;
    deque->arr[deque->right] = value;
    deque->right = (deque->right + 1) % deque->capacity;
}

void dq_appendLeft(Deque* deque, void* value) {
    if (dq_full(deque)) return;
    deque->left = (deque->left - 1) % deque->capacity;
    if (deque->left < 0) deque->left += deque->capacity;
    deque->arr[deque->left] = value;
}

void* dq_pop(Deque* deque) {
    if (dq_empty(deque)) return NULL;
    deque->right = (deque->right - 1) % deque->capacity;
    if (deque->right < 0) deque->right += deque->capacity;
    void* temp = deque->arr[deque->right];
    deque->arr[deque->right] = NULL;
    return temp;
}

void* dq_popLeft(Deque* deque) {
    if (dq_empty(deque)) return NULL;
    void* temp = deque->arr[deque->left];
    deque->arr[deque->left] = NULL;
    deque->left = (deque->left + 1) % deque->capacity;
    return temp;
}

// other queue properties
int dq_full(Deque* deque) {
    return deque->left == deque->right && deque->arr[deque->left];
}

int dq_empty(Deque* deque) {
    return deque->left == deque->right && !deque->arr[deque->left];
}

int dq_size(Deque* deque) {
    if (dq_full(deque)) return deque->capacity;
    int size = abs(deque->right - deque->left);
    if (deque->left > deque->right) return deque->capacity - size;
    return size;
}