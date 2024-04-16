//
// Created by 白天宇 on 2024/3/14.
//
#include "iostream"
#include "algorithm"
#include "vector"
#include "cstring"
#include "queue"
using namespace std;

class Solution{
public:
    int remove(vector<int>&nums,int val){
        int slow_index=0;
        for (int fast_index = 0; fast_index < nums.size(); fast_index++) {
            if (val!=nums[fast_index]){
                nums[slow_index++]=nums[fast_index];
            }
        }
        return slow_index;
    }
};


int main(){
    Solution solution;
    vector<int>nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    int result=solution.remove(nums,3);
    cout<<result<<endl;
    for (int i = 0; i < nums.size(); ++i) {
        cout<<nums[i]<<endl;
    }
    return 0;
}