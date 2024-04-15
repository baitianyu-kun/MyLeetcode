//
// Created by BAITIANYU on 2024/4/15.
//
#include "iostream"
#include "queue"
#include "vector"

using namespace std;

struct ListNode {

    int val;
    ListNode *next;

    ListNode &operator=(ListNode &&other) {
        if (this != &other) {
            delete next;
            val = other.val;
            next = other.next;
            other.next = nullptr;
        }
        return *this;
    }

    ListNode() {}

    ListNode(int x) : val(x), next(nullptr) {}
};

class Test {
public:
    ListNode *returnNode(ListNode *head) {
        ListNode *listNode;
        listNode = std::move(head);
        return listNode;
    }
};

int main() {
    Test test;
    ListNode *head = new ListNode(1);
    test.returnNode(head);
}
