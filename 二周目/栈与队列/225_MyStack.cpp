#include <iostream>
#include <queue>

//
// Created by polarnight on 23-9-22, 下午9:50.
//

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        queue_in.push(x);
    }

    int pop() {
        int size = static_cast<int>(queue_in.size()) - 1;
        while (size--) {
            queue_out.push(queue_in.front());
            queue_in.pop();
        }

        int res = queue_in.front();
        queue_in.pop();
        queue_in = queue_out;
        while (!queue_out.empty()) queue_out.pop();
        return res;
    }

    int top() {
        int res = this->pop();
        queue_in.push(res);
        return res;
    }

    bool empty() {
        return queue_in.empty() && queue_out.empty();
    }

private:
    std::queue<int> queue_in;
    std::queue<int> queue_out;
};

int main225() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    std::cout << myStack.top() << std::endl;
    std::cout << myStack.pop() << std::endl;
    std::cout << myStack.empty() << std::endl;

    return 0;
}