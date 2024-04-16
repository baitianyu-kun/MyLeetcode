//
// Created by 白天宇 on 2024/3/30.
//
#include "iostream"
#include "vector"
#include "unordered_map"
#include "algorithm"

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        unordered_map<int, int> temp_map;
        for (int a: nums1) {
            for (int b: nums2) {
                temp_map[a + b]++;
            }
        }
        int count =0;
        for (int c:nums3) {
            for (int d:nums4) {
                if (temp_map.find(0-(c+d))!=temp_map.end()){
                    count+=temp_map[0-(c+d)];
                }
            }
        }
        return count;

    }
};

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};
    Solution solution;
    solution.fourSumCount(nums1, nums2, nums3, nums4);
    return 0;
}