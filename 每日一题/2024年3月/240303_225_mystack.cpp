//
// Created by polarnight on 24-3-3, 下午2:33.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        que_in.push(x);
    }

    int pop() {
        int size = static_cast<int>(que_in.size()) - 1;
        while (size--) {
            que_in.push(que_in.front());
            que_in.pop();
        }

        int ret = que_in.front();
        que_in.pop();
        return ret;
    }

    int top() {
        return que_in.back();
    }

    bool empty() {
        return que_in.empty();
    }

private:
    queue<int> que_in;
};

int main2400303225() {

}