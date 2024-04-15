//
// Created by BAITIANYU on 2024/3/25.
//
#include "iostream"
#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(), next() {}

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *virtualNode = new ListNode;
        virtualNode->val = 0;
        virtualNode->next = head;
        ListNode *temp = virtualNode;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->val == val) {
                ListNode *tmp = temp->next;
                temp->next = temp->next->next;
                delete tmp;
            } else {
                temp = temp->next;
            }
        }
        return virtualNode->next;
    }
};


int main() {
    // head = [1,2,6,3,4,5,6], val = 6
    vector<int> nums = {7, 7, 7, 7};
    ListNode *head = new ListNode;
    head->val = 0;
    head->next = NULL;

    //保存头节点的信息 在循环结束时，head指向了链表的最后一个节点，而不是链表的头节点。
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
    ListNode *res = solution.removeElements(head, 6);
    cout << endl;
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}