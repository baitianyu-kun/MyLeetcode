//
// Created by BAITIANYU on 2024/4/15.
//
#include "iostream"
#include "stack"
#include "queue"

using namespace std;

class MyStack {
public:

    queue<int> queue1, queue2;

    MyStack() {

    }

    void push(int x) {
        queue1.push(x);
    }

    int pop() {
        int size = queue1.size();
        size--; //留下最后一个元素，就是要pop那一个
        while (size--) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int res = queue1.front();
        queue1.pop();
        queue1 = queue2;
        while (!queue2.empty()) {
            queue2.pop();
        }
        return res;
    }

    int top() {
        return queue1.back();
    }

    bool empty() {
        return queue1.empty();
    }
};

int main() {


}
