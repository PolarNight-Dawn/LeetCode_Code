//
// Created by polarnight on 24-3-4, 下午2:26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

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
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        int ret = stack_out.top();
        stack_out.pop();
        return ret;
    }

    int peek() {
        int ret = this->pop();
        stack_out.push(ret);
        return ret;
    }

    bool empty() {
        return stack_in.empty() && stack_out.empty();
    }

private:
    stack<int> stack_in;
    stack<int> stack_out;
};

int main240304232() {
    auto *obj = new MyQueue();

    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();

    cout << "param_2: " << param_2 << "param_3: " << param_3 << "param_4: " << param_4 << endl;

    delete obj;

    return 0;
}
