//
// Created by BAITIANYU on 2024/4/15.
//
#include "iostream"
#include "stack"
#include "queue"
#include "cstring"
#include "algorithm"

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (auto item: s) {
            if (st.empty() || st.top() != item) {
                st.push(item);
            } else {
                st.pop();
            }
        }
        string str = "";
        while (!st.empty()) {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

int main() {
    string s = "abbaca";
    Solution solution;
    string s2 = solution.removeDuplicates(s);

    cout << s2 << endl;

}