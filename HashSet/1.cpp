//
// Created by 白天宇 on 2024/3/30.
//
#include "iostream"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int,int> temp_map;
        for (int i = 0; i < nums.size(); ++i) {
            unordered_map<int,int>::iterator iter=temp_map.find(target-nums[i]);
            if (iter!=temp_map.end()){
                return {iter->second,i};
            }
            temp_map.insert(pair<int,int>(nums[i],i));
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    Solution solution;
    solution.twoSum(nums, 9);
    return 0;
}