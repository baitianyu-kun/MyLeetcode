//
// Created by BAITIANYU on 2024/3/25.
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
        ListNode *temp = virtual_head->next;
        int count = 0;
        while (temp != NULL) {
            if (count == index) {
                return temp->val;
            }
            temp = temp->next;
            count++;
        }
        return -1;
    }

    void seeall() {
        ListNode *temp = virtual_head->next;
        while (temp != NULL) {
            cout << temp->val;
            temp = temp->next;
        }
    }

    void seesize() {
        cout << endl << size << endl;
    }

    void addAtHead(int val) {
        ListNode *newNode = new ListNode;
        newNode->val = val;
        newNode->next = virtual_head->next;
        virtual_head->next = newNode;
        size++;
    }

    void addAtTail(int val) {
        ListNode *newNode = new ListNode;
        newNode->val = val;
        newNode->next = NULL;
        ListNode *temp = virtual_head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size - 1) {
            return;
        }
        if (index < 0) {
            index = 0;
        }
        int count = 0;
        ListNode *newNode = new ListNode;
        newNode->val = val;
        newNode->next = NULL;
        ListNode *temp = virtual_head;
        while (temp != NULL) {
            if (count == index) {
                newNode->next = temp->next;
                temp->next = newNode;
                size++;
                break;
            }
            count++;
            temp = temp->next;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= size || index < 0) {
            return;
        }
        ListNode* cur = virtual_head;
        while(index--) {
            cur = cur ->next;
        }
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        //delete命令指示释放了tmp指针原本所指的那部分内存，
        //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
        //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
        //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
        tmp=nullptr;
        size--;
    }

private:
    int size = 0;
    ListNode *virtual_head;

};


int main() {
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.addAtHead(2);
    myLinkedList.addAtHead(3);
    myLinkedList.addAtTail(5);
    myLinkedList.addAtIndex(0,6);
    myLinkedList.seeall();
//    cout << myLinkedList.get(3);
    return 0;
}
