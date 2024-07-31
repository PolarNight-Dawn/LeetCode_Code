//
// Created by polarnight on 24-7-28, 上午10:39.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canAliceWin(vector<int> &nums) {
	int signal_num, two_num;
	for (auto num : nums) {
	  if (num >= 10) two_num += num;
	  else signal_num += num;
	}
	if (signal_num == two_num) return false;
	return true;
  }
};

int main40801() {

}
