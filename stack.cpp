/*
    Implementation file for stack container.

    Includes push, pop, status, empty and isFull.
*/

#include <cassert>

// stack size
const int SIZE = 6;

// top of stack
int tos = -1;

// array stack
int stack[SIZE];

/*
    Check if there are no elements in the stack.

    @return whether the stack is empty
    @retval true stack empty
    @retval false at least on element in stack
*/
bool empty() {
    return tos == -1;
}

/*
    Check if the stack has the max number of elements.

    @return whether the stack is full
    @retval true stack is full
    @retval false stack is not full
*/
bool isFull() {
    return tos >= SIZE - 1;
}

/*
    Add an element to the top of stack.

    @return success or failure of pushing the element
    @retval 0 success
    @retval -1 failure
*/
int push(int element) {

    // fail if stack is full
    if(isFull())
        return -1;
    
    // add element to tos
    stack[++tos] = element;
    
    // return success code
    return 0;
}

/*
    Remove the top element from the stack.

    @return success or failure of removing the element
    @retval 0 success
    @retval -1 failure
*/
int pop() {

    // fail if stack is empty
    if(empty())
        return -1;
    
    // pop the element at tos
    stack[tos--] = 0;

    // return success code
    return 0;
}

int main() {

    // empty stack
    assert(empty());

    // push an element
    push(1);

    assert(!empty());
    assert(tos == 0);
    assert(stack[0] == 1);

    // pop an element
    pop();

    assert(empty());

    // full stack
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    assert(isFull());

    return 0;
}
