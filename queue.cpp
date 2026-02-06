/*
    Implementation file for queue container.

    Includes enqueue, dequeue, status, empty and isFull.
*/

// queue size
const int SIZE = 6;

// meta-pointers for front and back of queue
int head = 0;
int tail = 0;

// tracks whether queue is empty
bool empty = true;

// array queue
int queue[SIZE];
