//
// Created by BAITIANYU on 2024/4/15.
//
#include "iostream"
#include "queue"
#include "stack"

using namespace std;


class Solution {
public:
    stack<char> q;
    bool isValid(string s) {
        for (auto val: s) {
            if (val == '(') {
                q.push(')');
            } else if (val == '{') {
                q.push('}');
            } else if (val == '[') {
                q.push(']');
            } else if (q.empty() || q.top() != val) {
                return false;
            } else {
                q.pop(); // val == q.top的时候
            }
        }
        return q.empty(); // 如果为空，证明全部匹配，否则说明有的没有弹出
    }
};

int main() {

    string s = "()[]{}";
    Solution solution;
    bool res = solution.isValid(s);
    cout<<res;

}