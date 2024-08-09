#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1;  // Queue to hold the stack elements
    queue<int> q2;  // Auxiliary queue used during operations

public:
    MyStack() {
        // Constructor: Initialize the two queues
    }
    
    void push(int x) {
        // Push the new element onto q2
        q2.push(x);
        
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap q1 and q2 to make q1 the queue with all elements
        swap(q1, q2);
    }
    
    int pop() {
        // Remove and return the front element from q1
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
        // Return the front element of q1 (top of the stack)
        return q1.front();
    }
    
    bool empty() {
        // Check if q1 is empty (since q1 holds all the stack elements)
        return q1.empty();
    }
};

// Example usage
int main() {
    MyStack* obj = new MyStack();
    
    // Push elements
    obj->push(1);
    obj->push(2);
    obj->push(3);
    
    // Get the top element
    cout << "Top element: " << obj->top() << endl; // Output should be 3
    
    // Pop the top element
    cout << "Popped element: " << obj->pop() << endl; // Output should be 3
    
    // Check if stack is empty
    cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl; // Output should be No
    
    // Clean up
    delete obj;
    
    return 0;
}
