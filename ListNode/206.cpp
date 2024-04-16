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
        ListNode *tmp;
        ListNode *pre = NULL;
        while (cur != NULL) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
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
    head = head->next;
    Solution solution;
    ListNode *res = solution.reverseList(head);
    cout << endl;
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}