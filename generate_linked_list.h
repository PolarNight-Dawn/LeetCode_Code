//
// Created by polarnight on 23-9-7.
//

#ifndef LEEDCODE_GENERATE_LINKED_LIST_H
#define LEEDCODE_GENERATE_LINKED_LIST_H

#include <iostream>
#include <vector>

//! \链接阶段:编译器找不到 generate_linked_list::ListNodeUtils<int> 类的实现
//! 这种情况通常是因为模板类的实现需要包含在头文件中,而不是分离到独立的源文件中
namespace generate_linked_list {
    // 链表节点类
    template<typename T>
    struct ListNode {
        T val;
        ListNode<T> *next;

        // 使用 T() 构造默认值
        ListNode() : val(T()), next(nullptr) {}

        //! 单参数构造函数应该使用 \explicit 关键字进行标记，以避免不必要的隐式类型转换
        explicit ListNode(const T &val) : val(val), next(nullptr) {}

        ListNode(const T &item, ListNode<T> *next) : val(val), next(next) {}
    };

    template<typename T>
    class ListNodeUtils {
    public:
        ListNodeUtils() : head(nullptr) {}

        ~ListNodeUtils() {
            ListNode<T> *curr = head;
            while (curr) {
                ListNode<T> *next = curr->next;
                delete curr;
                curr = next;
            }
        }

        // ListNode<T> *GenerateLinkedList(std::vector<int> &nums, int len) {}

        void AddVal(const T &val) {
            ListNode<T> *node = new ListNode<T>(val);
            if (head == nullptr) {
                head = node;
            } else {
                ListNode<T> *curr = head;
                while (curr->next) {
                    curr = curr->next;
                }
                curr->next = node;
            }
        }

        void AddVal(const std::vector<T>& val) {
            for (const T &vec : val) {
                ListNode<T> *node = new ListNode<T>(vec);
                if (head == nullptr) {
                    head = node;
                } else {
                    ListNode<T> *curr = head;
                    while (curr->next) {
                        curr = curr->next;
                    }
                    curr->next = node;
                }
            }
        }

        int get_len() const {
            int len = 0;
            ListNode<T> *curr = head;
            while (curr) {
                len++;
                curr = curr->next;
            }
            return len;
        }

        void Print() const {
            ListNode<T> *curr = head;
            while (curr) {
                std::cout << curr->val << " ";
                curr = curr->next;
            }
            std::cout << std::endl;
        }

        ListNode<T> *get_head () const {
            return head;
        }

    private:
        ListNode<T> *head;
    };
}

#endif //LEEDCODE_GENERATE_LINKED_LIST_H
