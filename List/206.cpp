//
// Created by BAITIANYU on 2024/3/26.
//
#include "iostream"
#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(), next(NULL) {}
};

class Solution {
public:

    ListNode *reverseList(ListNode *head) {
        ListNode *cur = head;
        ListNode *pre;
        while (cur != NULL) {
            // ListNode *tmp_cur = cur;
            ListNode *tmp_pre = pre;
            pre=cur;
            cur = cur->next;
            pre->next = tmp_pre;
        }
        return pre;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    // virtual head
    ListNode *head = new ListNode;
    head->val = 0;
    head->next = NULL;
    ListNode *temp = head;
    for (int i = 0; i < nums.size(); ++i) {
        ListNode *newNode = new ListNode;
        newNode->val = nums[i];
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
    Solution solution;
    ListNode *res = solution.reverseList(head);
    cout << endl;
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}