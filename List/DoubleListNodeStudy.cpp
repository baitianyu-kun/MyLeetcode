//
// Created by BAITIANYU on 2024/3/25.
//
#include "iostream"
#include "vector"

using namespace std;

struct DoubleListNode {
    int val;
    DoubleListNode *pre;
    DoubleListNode *next;

    DoubleListNode() : val(), pre(NULL), next(NULL) {}
};

int main() {

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    DoubleListNode *head = new DoubleListNode;
    head->val = 0;
    head->pre = NULL;
    head->next = NULL;

    DoubleListNode *temp = head;
    for (int i = 0; i < nums.size(); i++) {
        DoubleListNode *newNode = new DoubleListNode;
        newNode->val = nums[i];
        newNode->next = NULL;
        newNode->pre = temp;
        temp->next = newNode;
        temp = newNode;
    }
    DoubleListNode *last = temp;
    while (last!=NULL){
        cout<<last->val<<" ";
        last=last->pre;
    }
    cout<<endl;
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }


    return 0;
}
