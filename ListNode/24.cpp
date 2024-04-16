//
// Created by 白天宇 on 2024/3/27.
//
#include "iostream"
#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
    ListNode() : val(), next() {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *virtual_head = new ListNode;
        virtual_head->val = 0;
        virtual_head->next = head;
        ListNode *cur = virtual_head;
        while (cur->next != NULL && cur->next->next != NULL) {
            ListNode *need_swap_1 = cur->next;
            ListNode *need_swap_2 = cur->next->next;
            ListNode *save_old = cur->next->next->next;
            cur->next = need_swap_2;
            cur->next->next = need_swap_1;
            cur->next->next->next = save_old;
            cur = cur->next->next;
        }
        return virtual_head->next;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
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
    ListNode *res = solution.swapPairs(head);
    cout << endl;
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}