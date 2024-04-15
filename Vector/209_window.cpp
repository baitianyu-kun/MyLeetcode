//
// Created by BAITIANYU on 2024/3/25.
//
#include "iostream"
#include "vector"
#include "algorithm"
#include "cstdint"

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int i = 0;
        int result = 0;
        int min_len = INT32_MAX;
        for (int j = 0; j < nums.size(); ++j) {
            result += nums[j];
            while (result >= target) {
                int sub_len=j-i+1;
                if (sub_len< min_len){
                    min_len=sub_len;
                }
                result-=nums[i++];
            }
        }
        if (min_len==INT32_MAX){
            return 0;
        }else{
            return min_len;
        }
    }
};

int main() {

    Solution solution;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int res=solution.minSubArrayLen(7, nums);
    cout<<res;
    return 0;
}