#include <iostream>

//
// Created by polarnight on 23-9-8, 下午4:34.
//

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        explicit ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}

    };

    MyLinkedList() {
        this->head = new MyLinkedList::ListNode(0);
        this->size_ = 0;
    }

    int get(int index) {
        ListNode *cur = head;
        if (index < 0 || index >= size_) return -1;

        while (index >= 0) {
            cur = cur->next;
            index--;
        }

        return  cur->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size_, val);
    }

    void addAtIndex(int index, int val) {
        if (index > size_) return;
        index = std::max(0, index);
        auto *node = new MyLinkedList::ListNode(val);
        ListNode *cur = head;

        while (index) {
            cur = cur->next;
            index--;
        }
        node->next = cur->next;
        cur->next = node;
        size_++;
    }

    void deleteAtIndex(int index) {
        ListNode *cur = head;
        if (index >= size_ || index < 0) return;

        while (index) {
            cur = cur->next;
            index--;
        }
        ListNode *node = cur->next;
        cur->next = cur->next->next;
        delete node;
        size_--;
    }

private:
    int size_;
    ListNode *head;
};

int main() {
    auto *obj = new MyLinkedList();
    int param_1 = obj->get(1);
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    obj->deleteAtIndex(1);

    return 0;
}