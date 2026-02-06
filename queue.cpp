/*
    Implementation file for queue container.

    Includes enqueue, dequeue, status, isEmpty and isFull.
*/

#include <cassert>

// queue size
const int SIZE = 6;

// meta-pointers for front and back of queue
int head = 0;
int tail = 0;

// tracks whether queue is empty
bool empty = true;

// array queue
int queue[SIZE];

/*
    Check if there are no elements in the queue.

    @return Whether the queue is empty
    @retval true Queue empty
    @retval false At least on element in queue
*/
bool isEmpty() {
    return empty;
}

/*
    Add an element to the back of the queue.

    @return Success or failure of enqueueing the element
    @retval 0 Success
    @retval -1 Failure
*/
int enqueue(int element) {

    // fail if the queue is full
    if (head == tail && !empty)
        return -1;

    // add element to back of queue
    queue[tail] = element;
    tail = (tail + 1) % SIZE;

    // queue is no longer empty
    empty = false;

    return 0;
}

int main() {

    // empty queue
    assert(isEmpty());

    // add an element
    enqueue(1);

    assert(!isEmpty());
    assert(head == 0);
    assert(tail == 1);

    return 0;
}
