//
// Created by 白天宇 on 2024/4/12.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }
        // 归位，然后对齐末位进行遍历，注意是判断指针是否相同
        curA = headA;
        curB = headB;
        // 让A是较长的那个
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int offset = lenA - lenB;
        // 让A末位对齐B
        while (offset--) {
            curA = curA->next;
        }
        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};


int main() {
    vector<int> nums = {0, 9, 1, 2, 4};
    vector<int> nums2 = {3};

    ListNode *l1 = create_linked(nums);
    ListNode *l2 = create_linked(nums2);

    ListNode *curl1 = l1;
    ListNode *curl2 = l2;
    curl2->next = curl1->next->next->next;

    print_linked(l1);
    print_linked(l2);

    Solution solution;
    ListNode *res = solution.getIntersectionNode(l1, l2);
    cout<<res->val;



    return 0;

}