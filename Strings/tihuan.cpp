//
// Created by 白天宇 on 2024/4/8.
//
#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main() {

    string s;
    while (cin >> s) {
        int old_index = s.size() - 1;
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' || s[i] <= '9') {
                count++;
            }
        }
        s.resize(s.size() + count * 5);
        int new_index = s.size() - 1;
        while (old_index >= 0) {
            if (s[old_index] >= '0' && s[old_index] <= '9'){
                s[new_index--] = 'r';
                s[new_index--] = 'e';
                s[new_index--] = 'b';
                s[new_index--] = 'm';
                s[new_index--] = 'u';
                s[new_index--] = 'n';
            }else{
                s[new_index--] = s[old_index       }
        cout<<s<<endl;
    }


}