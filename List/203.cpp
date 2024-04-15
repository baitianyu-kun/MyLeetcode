//
// Created by BAITIANYU on 2024/3/25.
//
#include "iostream"
#include "algorithm"
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
        // 删除头节点
        while (head != NULL && head->val == val) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        // 删除非头节点
        ListNode *temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->val == val) {
                ListNode *deletes = temp->next;
                temp->next = temp->next->next;
                delete deletes;
            } else { temp = temp->next; }
        }
        return head;
    }
};

int main() {
    // head = [1,2,6,3,4,5,6], val = 6
    vector<int> nums = {1, 2, 6, 3, 4, 5, 6};
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
//    while (head != NULL) {
//        cout << head->val << " ";
//        head = head->next;
//    }

    Solution solution;
    ListNode *res = solution.removeElements(head, 6);
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}