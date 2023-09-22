#include <iostream>
#include <stack>

//
// Created by polarnight on 23-9-22, 下午9:07.
//

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        stack_in.push(x);
    }

    int pop() {
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                int tmp = stack_in.top();
                stack_in.pop();
                stack_out.push(tmp);
            }
        }
        int res = stack_out.top();
        stack_out.pop();
        return res;
    }

    int peek() {
        int res = this->pop();
        stack_out.push(res);
        return res;
    }

    bool empty() {
        return stack_out.empty() && stack_in.empty();
    }

private:
    std::stack<int> stack_in;
    std::stack<int> stack_out;
};

int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    std::cout << queue.peek() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.empty() << std::endl;

    return 0;
}