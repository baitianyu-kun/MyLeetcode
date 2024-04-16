//
// Created by 白天宇 on 2024/4/15.
//
#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() {}

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *create_linked(vector<int> &nums) {
    ListNode *head = new ListNode;
    head->val = 0;
    head->next = nullptr;
    ListNode *temp = head;
    for (int i = 0; i < nums.size(); ++i) {
        ListNode *newNode = new ListNode;
        newNode->val = nums[i];
        newNode->next = nullptr;
        temp->next = newNode;
        temp = newNode;
    }
    return head->next;
}

void print_linked(ListNode *&head) {
    ListNode *temp2 = head;
    while (temp2 != nullptr) {
        cout << temp2->val << " ";
        temp2 = temp2->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummyHead = new ListNode;
        dummyHead->next = head;
        ListNode *fast = dummyHead;
        ListNode *slow = dummyHead;
        n += 1; //fast移动n+1步，slow才正好在删除的上一位
        while (n--) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        // slow到了要删除的上一位
        ListNode *tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        return dummyHead->next;
    }
};


int main() {
    vector<int> nums = {0, 9, 1, 2, 4};
    ListNode *l1 = create_linked(nums);
    Solution solution;
    ListNode *res = solution.removeNthFromEnd(l1,2);
    print_linked(res);

    return 0;

}