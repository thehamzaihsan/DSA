#include <iostream>
#include <stack>

void deleteMiddleElement(std::stack<int>& stk) {
    int size = stk.size();
    int middle = size / 2;

    std::stack<int> tempStk;

    // Remove elements until the middle element is reached
    for (int i = 0; i < middle; i++) {
        tempStk.push(stk.top());
        stk.pop();
    }

    // Skip the middle element
    stk.pop();

    // Push back the remaining elements from the temporary stack
    while (!tempStk.empty()) {
        stk.push(tempStk.top());
        tempStk.pop();
    }
}

int main() {
    std::stack<int> stk;

    // Push elements into the stack
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    std::cout << "Stack before deletion: ";
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }

    std::cout << std::endl;

    // Delete the middle element
    deleteMiddleElement(stk);

    std::cout << "Stack after deletion: ";
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }

    std::cout << std::endl;

    return 0;
}