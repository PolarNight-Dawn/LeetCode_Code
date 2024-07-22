//
// Created by polarnight on 24-7-21, 上午10:41.
//

#include <iostream>

class Solution {
 public:
  int minChanges(int n, int k) {
	if ((n & k) != k)
	  return -1;

	int diff = n ^ k;
	int ant = 0;

	while (diff) {
	  if ((diff & 1) && (n & 1))
		ant++;
	  diff = diff >> 1;
	  n = n >> 1;
	}

	return ant;
  }
};

int main100372() {

}
