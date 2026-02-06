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
    Add an element to the top of stack.

    @return success or failure of pushing the element
    @retval 0 success
    @retval -1 failure
*/
int push(int element) {

    // fail if stack is full
    if(tos >= (SIZE - 1))
        return -1;
    
    // add element to tos
    stack[++tos] = element;
    
    // return success code
    return 0;
}

int main() {

    // empty stack
    {
        assert(empty());
    }

    // push an element
    {
        push(1);

        assert(!empty());
        assert(tos == 0);
        assert(stack[0] == 1);

    }

    return 0;
}
