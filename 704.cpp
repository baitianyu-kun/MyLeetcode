#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Solution{
public:
    int search(vector<int> &nums,int target){
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int middle=left+((right-left)/2);
            if(nums[middle]>target){
                right=middle-1;
            }else if (nums[middle]<target){
                left=middle+1;
            }else{
                return middle;
            }
        }
        return -1;
    }
};


int main() {
    Solution solution;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(9);
    nums.push_back(10);
    nums.push_back(11);
    nums.push_back(12);
    int result=solution.search(nums,3);
    cout<<result<<endl;
    return 0;
}
