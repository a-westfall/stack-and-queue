/*
    Implementation file for stack container.

    Includes push, pop, empty and isFull.
*/

#include <cassert>

// stack size
const int SIZE = 6;

// top of stack
int tos = -1;

/*
    Check if there are no elements in the stack.

    @return whether the stack is empty
    @retval true stack empty
    @retval false at least on element in stack
*/
bool empty() {
    return tos == -1;
}

int main() {

    {
        int stack[SIZE];

        assert(empty());
    }

    return 0;
}
