//
// Created by 白天宇 on 2024/3/18.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution{
public:
    vector<int> sorts(vector<int> &A){
        int k = A.size()-1;
        int j = A.size()-1;
        vector<int> result(A.size(),0);
        for (int i = 0; i <= j;) {
            if (A[i]*A[i]<A[j]*A[j]){
                result[k]=A[j]*A[j];
                j--;
            }else{
                result[k]=A[i]*A[i];
                i++;
            }
            k--;
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> A;
    A.push_back(-4);
    A.push_back(-1);
    A.push_back(0);
    A.push_back(3);
    A.push_back(10);
    vector<int> result=solution.sorts(A);
    for (int i = 0; i < result.size(); i++) {
        cout<<result[i];
    }
    return 0;
}