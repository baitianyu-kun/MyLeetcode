//
// Created by 白天宇 on 2024/3/24.
//
#include "iostream"
#include "vector"
#include "algorithm"
#include "cstring"
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int i=0;
        string min_len_substr;
        string sum("");
        for (int j = 0; j < s.size(); j++) {
            if (t.find(s[j])!=t.npos){
                sum.append(1,s[j]);

            }
        }
        return "";
    }
};

int main(){
    Solution solution;
    string s("ADOBECODEBANC");
    string t("ABC");
    solution.minWindow(s,t);
    return 0;
}