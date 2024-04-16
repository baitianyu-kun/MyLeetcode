//
// Created by 白天宇 on 2024/4/1.
//
#include "iostream"
#include "vector"
#include "cstring"

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution solution;
    solution.reverseString(s);
    return 0;
}