/*
    Implementation file for stack container.

    Includes push, pop, status, empty and isFull.
*/

#include <iostream>
#include <cassert>

// stack size
const int SIZE = 6;

// top of stack meta-pointer
int tos = -1;

// array stack
int stack[SIZE];

/*
    Check if there are no elements in the stack.

    @return Whether the stack is empty
    @retval true Stack empty
    @retval false At least on element in stack
*/
bool empty() {
    return tos == -1;
}

/*
    Check if the stack has the max number of elements.

    @return Whether the stack is full
    @retval true Stack is full
    @retval false Stack is not full
*/
bool isFull() {
    return tos >= SIZE - 1;
}

/*
    Add an element to the top of stack.

    @param element Item to be added to stack
    @return Success or failure of pushing the element
    @retval 0 Success
    @retval -1 Failure
*/
int push(int element) {

    // fail if stack is full
    if (isFull()) {
        std::cerr << "ERROR. Unable to push element. Stack is full.\n\n";

        return -1;
    }
    
    // add element to tos
    stack[++tos] = element;
    
    // return success code
    return 0;
}

/*
    Remove the top element from the stack.

    @return Success or failure of removing the element
    @retval 0 Success
    @retval -1 Failure
*/
int pop() {

    // fail if stack is empty
    if (empty()) {
        std::cerr << "ERROR. Unable to pop element. Stack is empty.\n\n";
        return -1;
    }
    
    // pop the element at tos
    stack[tos--] = 0;

    // return success code
    return 0;
}

/*
    View stack contents and tos.

    @param out Output stream that is written to 
    @return Ostream containing array contents and tos meta-pointer
*/
std::ostream& status(std::ostream& out) {

    // add array contents to ostream
    out << "Array contents: \n";
    for (int i = 0; i < SIZE; ++i) {
        out << i << ":  " << stack[i] << "\n";
    }

    // add tos and its contents to ostream
    out << "\nCurrent TOS: " << tos << "\n";
    out << "Element at TOS: " << stack[tos] << "\n\n";

    return out;
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

    // push to full stack
    push(1);

    assert(isFull());
    assert(tos == SIZE - 1);

    // stack status
    pop();
    status(std::cout);

    assert(!empty());
    assert(!isFull());
    assert(tos == 4);

    // pop entire stack
    pop();
    pop();
    pop();
    pop();
    pop();

    status(std::cout);

    assert(empty());
    assert(!isFull());

    // pop from empty stack
    pop();

    assert(empty());
    assert(tos == -1);

    // push and pop elements
    push(3);
    push(245);
    push(43);
    pop();
    push(34);
    push(21);
    push(1);
    pop();
    pop();
    
    status(std::cout);

    assert(!empty());
    assert(!isFull());
    assert(tos == 2);

    return 0;
}
