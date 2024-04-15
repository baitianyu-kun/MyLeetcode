//
// Created by BAITIANYU on 2024/3/26.
//
#include "iostream"
#include "vector"

using namespace std;

class MyLinkedList {

public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(), next(NULL) {}
    };

    MyLinkedList() {
        virtual_head = new ListNode;
        virtual_head->val = 0;
        virtual_head->next = NULL;
    }

    int get(int index) {
//        cout<<"index "<<index<<" size "<<size<<endl;
        if (index > (size - 1) || index < 0) {
            return -1;
        }
        ListNode *temp = virtual_head;
        while (index--) {
            temp = temp->next;
        }
        return temp->next->val;
    }

    void printALL() {
        ListNode *temp = virtual_head;
        while (temp->next != NULL) {
            cout << temp->next->val << " ";
            temp = temp->next;
        }
    }

    void addAtHead(int val) {

        ListNode *newNode = new ListNode;
        newNode->val = val;
        ListNode *temp = virtual_head;
        newNode->next = temp->next;
        temp->next = newNode;
        size++;

    }

    void addAtTail(int val) {
        ListNode *newNode = new ListNode;
        newNode->val = val;
//        newNode->next = NULL;
        ListNode *temp = virtual_head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        if (index < 0) {
            index = 0;
        }
        ListNode *temp = virtual_head;
        while (index--) {
            temp = temp->next;
        }
        ListNode *newNode = new ListNode;
        newNode->val = val;
        newNode->next = temp->next;
        temp->next = newNode;
        size++;

    }

    void deleteAtIndex(int index) {
        if (index >= size|| index < 0) {
            return;
        }
        ListNode *temp = virtual_head;
        while (index--) {
            temp = temp->next;
        }
        ListNode *delete_tmp = temp->next;
        temp->next = temp->next->next;
        delete delete_tmp;
        size--;

    }

private:
    int size = 0;
    ListNode *virtual_head;

};

int main() {
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(7);
    myLinkedList.addAtHead(2);
    myLinkedList.addAtHead(1);
    myLinkedList.addAtIndex(3, 0);
    myLinkedList.deleteAtIndex(2);
    myLinkedList.addAtHead(6);
    myLinkedList.addAtTail(4);
//    myLinkedList.printALL();
    cout << myLinkedList.get(4);
    myLinkedList.addAtHead(4);
    myLinkedList.addAtIndex(5, 0);
    myLinkedList.addAtHead(6);
//    myLinkedList.printALL();
    return 0;
}