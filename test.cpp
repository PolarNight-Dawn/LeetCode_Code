#include <iostream>
#include <vector>

#include "generate_linked_list.h"

using namespace std;
//
// Created by polarnight on 23-4-14.
//

int main00() {
    generate_linked_list::ListNodeUtils<int> mylist;
    std::vector<int> nums = {1, 2, 3};
    mylist.AddVal(nums);

    mylist.Print();
    std::cout << "length: " << mylist.get_len() << std::endl;

    generate_linked_list::ListNode<int> *head = mylist.get_head();

    return 0;
}




