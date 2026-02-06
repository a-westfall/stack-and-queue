/*
    Implementation file for queue container.

    Includes enqueue, dequeue, status, empty and isFull.
*/

#include <cassert>

// queue size
const int SIZE = 6;

// meta-pointers for front and back of queue
int head = 0;
int tail = 0;

// tracks whether queue is empty
bool isEmpty = true;

// array queue
int queue[SIZE];

/*
    Check if there are no elements in the queue.

    @return Whether the queue is empty
    @retval true Queue empty
    @retval false At least on element in queue
*/
bool empty() {
    return isEmpty;
}

int main() {

    // empty queue
    assert(empty());

    return 0;
}
