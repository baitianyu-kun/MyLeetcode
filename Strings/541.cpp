//
// Created by 白天宇 on 2024/4/1.
//
#include "iostream"
#include "cstring"
#include "vector"
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i+=(2*k)) {
            if (i+k<=s.size()){
                reverse(s.begin()+i,s.begin()+i+k);
            }else{
                reverse(s.begin()+i,s.end());
            }
        }
        return s;
    }
};

int main(){
    string s="abcdefg";
    Solution solution;
    solution.reverseStr(s,2);
    return 0;
}