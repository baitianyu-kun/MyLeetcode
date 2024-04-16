//
// Created by 白天宇 on 2024/3/30.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
//    双指针法
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> original_nums;
        original_nums.assign(nums.begin(),nums.end());
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int sum=nums[left]+nums[right];
            if (sum==target){
                vector<int>::iterator iter1= find(original_nums.begin(),original_nums.end(),nums[left]);
                int left1=iter1-original_nums.begin();
                vector<int>::iterator iter2= find(original_nums.begin(),original_nums.end(),nums[right]);
                int right1=iter2-original_nums.begin();
                if (left1==right1){
                    vector<int>::iterator iter3= find(original_nums.begin()+left1+1,original_nums.end(),nums[right]);
                    right1=iter3-original_nums.begin();
                }
                cout<<left1<<" "<<right1;
                return {left1,right1};
            }
            if (sum>target){
                right--;
            }
            if (sum<target){
                left++;
            }
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2,5,5,11};
    Solution solution;
    solution.twoSum(nums, 10);
    return 0;
}