//
// Created by 白天宇 on 2024/4/17.
//
#include "iostream"
#include "deque"

using namespace std;

class Solution {
private:
    // 单调队列，设计原则：
    // pop(value)：如果窗口移除的元素value等于单调队列的出口元素，那么队列弹出元素，否则不用任何操作
    // push(value)：如果push的元素value大于入口元素的数值，那么就将队列入口的元素弹出，直到push元素的数值小于等于队列入口元素的数值为止
    class MyQueue {
    public:
        deque<int> de;

        // pop时候要保证pop队首时候和要pop的值相等
        void pop(int val) {
            if (!de.empty() && val == de.front()) {
                de.pop_front();
            }
        }

        void push(int val) {
            while (!de.empty() && val > de.back()) {
                // 因为是单调的，从大到小，所以从屁股开始判断，如果比val小就pop掉，这样就剩下从大到小的了
                de.pop_back();
            }
            de.push_back(val);
        }

        // 从大到小，第一个是最大的
        int max_val() {
            return de.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        MyQueue myQueue;
        // 前k个先加进来，然后删掉队头，并加入新的元素
        for (int i = 0; i < k; ++i) {
            myQueue.push(nums[i]);
        }
        vector<int> max_vals;
        max_vals.push_back(myQueue.max_val());
        for (int i = k; i < nums.size(); ++i) {
            myQueue.pop(nums[i - k]); // pop掉第一个
            myQueue.push(nums[i]);
            max_vals.push_back(myQueue.max_val());
        }
        return max_vals;
    }
};

int main() {

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    Solution solution;
    vector<int> res = solution.maxSlidingWindow(nums, 3);
    for (auto &r: res) {
        cout << r << " " << endl;
    }
}