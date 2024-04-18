//
// Created by 白天宇 on 2024/4/17.
//
#include "iostream"
#include "stack"
#include "vector"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for (auto &token: tokens) {
            if (token == "+") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 + num1);
            } else if (token == "-") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 - num1);
            } else if (token == "*") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 * num1);
            } else if (token == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(int(num2 / num1));
            } else {
                // 转换为整数
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};

int main() {

    vector<string> tokens = {"3","11","5","+","-"};
    Solution solution;
    int res = solution.evalRPN(tokens);
    cout<<res;
}