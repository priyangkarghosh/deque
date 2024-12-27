#ifndef DEQUEUE_H
#define DEQUEUE_H

// generic implementation of a double ended queue
// -> uses a circular array
// -> although the program doesn't need the queue to be double ended
//    the code is almost the same, so might as well
typedef struct {
    int capacity;
    int left, right;
    void** arr;
} Deque;

// create/destroy functions
Deque* dq_create(int capacity);
void dq_clear(Deque* deque);
void dq_free(Deque* deque);

// operations for the right side
void dq_append(Deque* deque, void* value);
void* dq_pop(Deque* deque);

// operations for the left side
void dq_appendLeft(Deque* deque, void* value);
void* dq_popLeft(Deque* deque);

// other queue properties
int dq_full(Deque* deque);
int dq_empty(Deque* deque);
int dq_size(Deque* deque);

#endif
