//
// Created by BAITIANYU on 2024/4/15.
//
#include "iostream"
#include "stack"

using namespace std;

class MyQueue {
public:
    stack<int> stack_in;
    stack<int> stack_out;

    MyQueue() {

    }

    void push(int x) {
        stack_in.push(x);
    }

    int pop() {
        // stack out为空的时候进行导入
        if (stack_out.empty()) {
            // stack in进行导入
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
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
        // 进出都为空的时候说明队列为空
        return stack_in.empty()&&stack_out.empty();
    }
};

int main() {


}