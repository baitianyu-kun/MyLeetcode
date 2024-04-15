//
// Created by BAITIANYU on 2024/3/25.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maxLength(vector<int> &A, vector<int> &B) {
        int nums_len = A.size() < B.size() ? A.size():B.size();
        int max_len = 0;
        int k = 0;
        for (int i = 0; i < nums_len; ++i) {
            if (A[i] == B[i]) {
                k++;
            } else {
                k = 0;
            }
            if (max_len < k) {
                max_len = k;
            }
        }
        return max_len;
    }

    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int max_len = 0;
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; ++i) {
            vector<int> A;
            A.assign(nums1.begin() + i, nums1.end());
            vector<int> B;
            B.assign(nums2.begin(), nums2.end());
            int temp_max_len = maxLength(A, B);
            max_len = temp_max_len > max_len ? temp_max_len : max_len;
        }
        for (int j = 0; j < m; ++j) {
            vector<int> A;
            A.assign(nums2.begin() + j, nums2.end());
            vector<int> B;
            B.assign(nums1.begin(), nums1.end());
            int temp_max_len = maxLength(A, B);
            max_len = temp_max_len > max_len ? temp_max_len : max_len;
        }
        return max_len;

    }
};

int main() {
    Solution solution;
    vector<int> num1 = {1,2,3,2,1};
    vector<int> num2 = {3,2,1,4};
    int maxlen=solution.findLength(num1, num2);
    cout<<maxlen;
    return 0;
}