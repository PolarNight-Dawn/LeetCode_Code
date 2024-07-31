//
// Created by polarnight on 24-7-21, 上午11:40.
//

#include <iostream>

/* 贪心，从左到右思考 */
int maxOperations(const std::string &s) {
  int ans = 0, cnt = 0;

  for (int i = 0; i < s.size(); ++i) {
	if (s[i] == '1') {
	  cnt++;
	} else if (i && s[i - 1] == '1') {
	  ans += cnt;
	}
  }

  return ans;
}

int main40703() {
  std::string s = "1001101";
  std::cout << maxOperations(s) << std::endl;
  return 0;
}
