//
// Created by 白天宇 on 2024/4/1.
//
#include "unordered_map"
#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> temp_map1;
        for (int i = 0; i < magazine.size(); ++i) {
            temp_map1[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.size(); ++i) {
            temp_map1[ransomNote[i]]--;
        }
        for (unordered_map<char,int>::iterator iter = temp_map1.begin();  iter!=temp_map1.end() ; iter++) {
            if (iter->second<0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    string s1="aa";
    string s2="ab";
    Solution solution;
    bool res=solution.canConstruct(s1,s2);
    cout<<res<<endl;
    return 0;
}