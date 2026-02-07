/*
    Implementation file for queue container.

    Includes enqueue, dequeue, status, isEmpty and isFull.
*/

#include <iostream>
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
    Check if the queue has the max number of elements.

    @return Whether the queue is full
    @retval true Queue is full
    @retval false Queue is not full
*/
bool isFull() {
    return head == tail && !empty;
}

/*
    Add an element to the back of the queue.

    @param element Item to be added to the queue
    @return Success or failure of enqueueing the element
    @retval 0 Success
    @retval -1 Failure
*/
int enqueue(int element) {

    // fail if the queue is full
    if (isFull()) {
        std::cerr << "ERROR. Unable to enqueue element. Queue is full.\n\n";
        return -1;
    }

    // add element to back of queue
    queue[tail] = element;
    tail = (tail + 1) % SIZE;

    // queue is no longer empty
    empty = false;

    // return success code
    return 0;
}

/*
    Remove the top element from the queue.

    @return Success or failure of removing the element
    @retval 0 Success
    @retval -1 Failure
*/
int dequeue() {

    // fail if queue is empty
    if (isEmpty()) {
        std::cerr << "ERROR. Unable to dequeue element. Queue is empty.\n\n";
        return -1;
    }
    
    // remove front element
    queue[head] = 0;
    head = (head + 1) % SIZE;

    // check if queue empty
    if (head == tail)
        empty = true;
    
    // return success code
    return 0;
}

/*
    View queue contents and tos.

    @param out Output stream that is written to 
    @return Ostream containing array contents and head and tail meta-pointers
*/
std::ostream& status(std::ostream& out) {

    // add array contents to ostream
    out << "Array contents: \n";
    for (int i = 0; i < SIZE; ++i) {
        out << i << ":  " << queue[i] << "\n";
    }

    // add head, tail and their contents to ostream
    out << "\nCurrent head: " << head << "\n";
    out << "Element at head: " << queue[head];
    out << "\nCurrent tail: " << tail << "\n";
    out << "Element at tail: " << queue[tail] << "\n\n";

    return out;
}

int main() {

    // empty queue
    assert(isEmpty());

    // add an element
    enqueue(1);

    assert(!isEmpty());
    assert(head == 0);
    assert(tail == 1);

    // remove an element
    dequeue();

    assert(isEmpty());
    assert(head == 1);
    assert(tail == 1);

    // dequeue from empty queue
    dequeue();

    assert(isEmpty());
    assert(head == 1);
    assert(tail == 1);

    // full queue
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);

    assert(isFull());

    // enqueue to full queue
    enqueue(23);

    assert(head == 1);
    assert(tail == 1);
    assert(queue[head] == 1);
    assert(queue[tail] == 1);

    // queue status
    dequeue();
    status(std::cout);

    assert(!isFull());
    assert(!isEmpty());
    assert(head == 2);
    assert(tail == 1);

    // enqueue and dequeue elements
    dequeue();
    dequeue();
    enqueue(23);
    enqueue(44);
    enqueue(21);
    dequeue();

    status(std::cout);

    assert(!isEmpty());
    assert(!isFull());
    assert(head == 5);
    assert(tail == 4);

    return 0;
}
