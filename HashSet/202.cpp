//
// Created by 白天宇 on 2024/3/27.
//
#include "iostream"
#include "unordered_set"
using namespace std;

class Solution {
public:

    int getnums(int n){
        int sum=0;
        while (n){
            sum+=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> sum;
        while (1){
            int res= getnums(n);
            if (res==1){
                return true;
            }
            if (sum.find(res)!=sum.end()){
                return false;
            }else{
                sum.insert(res);
            }
            n=res;
        }

    }
};

int main(){
    Solution solution;
    cout<<solution.isHappy(19);
    return 0;
}