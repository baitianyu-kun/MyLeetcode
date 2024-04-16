//
// Created by 白天宇 on 2024/3/20.
//
#include "iostream"
#include "vector"
#include "algorithm"
#include "stdint.h"
using namespace std;

class Solution{
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i=0;
        int result=0;
        int min_len=INT32_MAX;
        for (int j = 0; j < nums.size(); j++) {
            result+=nums[j];
            while (result>=s){
                int sub_len=(j-i)+1;
                if (sub_len<min_len){
                    min_len=sub_len;
                }
                result-=nums[i++];
            }
        }
        if (min_len==INT32_MAX){
            return 0;
        } else {
            return min_len;
        }
    }
};

int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    Solution solution;
    int result=solution.minSubArrayLen(7,nums);
    cout<<result;
    return 0;
}