//
// Created by 白天宇 on 2024/3/27.
//
#include "iostream"
#include "unordered_set"
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int record[1001]={0};
        vector<int> nums;


        for (int i = 0; i < nums1.size(); ++i) {
            record[nums1[i]]+=1;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            int temp=record[nums2[i]];
            record[nums2[i]]-=1;
            if (record[nums2[i]]==0 || temp>=2){
                nums.push_back(nums2[i]);
            }
        }
        unordered_set<int> reduce_nums(nums.begin(),nums.end());
        return vector<int>(reduce_nums.begin(),reduce_nums.end());

    }
};

int main(){
    Solution solution;
    vector<int> nums1={1,2,2,1};
    vector<int> nums2={2};
    vector<int> res=solution.intersection(nums1,nums2);
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<" ";
    }
    return 0;
}