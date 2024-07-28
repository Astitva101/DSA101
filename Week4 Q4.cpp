/*Question:
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support
 all the functions of a normal queue (push, peek, pop, and empty).*/

 #include <stack>

class MyQueue {
private:
    std::stack<int> stack1;
    std::stack<int> stack2;

    // Helper function to move elements from stack1 to stack2
    void transferStack1ToStack2() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        if (stack2.empty()) {
            transferStack1ToStack2();
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }
    
    int peek() {
        if (stack2.empty()) {
            transferStack1ToStack2();
        }
        return stack2.top();
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */