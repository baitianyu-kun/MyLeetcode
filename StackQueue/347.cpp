//
// Created by 白天宇 on 2024/4/17.
//
#include "iostream"
#include "deque"
#include "queue"

using namespace std;

class Solution {
public:
    class c_compare {
    public:
        bool operator()(const pair<int, int> &source, const pair<int, int> &target) {
            return source.second > target.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> maps;
        for (int i = 0; i < nums.size(); ++i) {
            maps[nums[i]]++; // 统计出现次数
        }
        // 小顶堆，最顶上是最小的，大小为k
        // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
        // 因为小顶堆先弹出的是最小的，所以剩下的为最大的，并按照从小到大排序，所以需要倒序输出到数组
        priority_queue<pair<int, int>, vector<pair<int, int>>, c_compare> pq;
        for (auto &iter: maps) {
            pq.push(iter);
            if (pq.size() > k) {
                pq.pop(); //如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
            }
        }

        // 倒序输出到数组
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = pq.top().first;// 存的是元素名
            pq.pop();// 别忘记弹出
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    Solution solution;
    vector<int> res = solution.topKFrequent(nums,2);
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<" ";
    }
}