//
// Created by 白天宇 on 2024/3/27.
//
#include "iostream"
using namespace std;

int main(){

    string s="anagram";
    string t="nagaram";
    int record[26] = {0};
    for (int i = 0; i < s.size(); ++i) {
        record[s[i]-'a']+=1;
    }
    for (int i = 0; i < t.size(); ++i) {
        record[t[i]-'a']-=1;
    }
    for (int i = 0; i < 26; ++i) {
        if (record[i]!=0){
            return false;
        }
        return true;
    }

}