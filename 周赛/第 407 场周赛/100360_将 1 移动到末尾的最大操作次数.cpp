//
// Created by polarnight on 24-7-21, 上午11:40.
//

#include <iostream>


// int maxOperations(std::string s) {
//   int ant = 0;
//   bool found = true;
//
//   while (found) {
// 	found = false;
// 	for (size_t i = 0; i + 1 < s.size(); ++i) {
// 	  if (s[i] == '1' && s[i + 1] == '0') {
// 		found = true;
// 		ant++;
// 		size_t j = i;
// 		while (j + 1 < s.size() && s[j + 1] == '0') {
// 		  std::swap(s[j], s[j + 1]);
// 		  j++;
// 		}
// 		break;
// 	  }
// 	}
//   }
//
//   return ant;
// }

int maxOperations(const std::string &s) {
  int ant = 0;
  int zero_count = 0;

  for (int i = s.size() - 1; i >= 0; --i) {
	if (s[i] == '1')
	  ant += zero_count;
  }

  return ant;
}

int main() {
  std::string s = "1001101";
  std::cout << maxOperations(s) << std::endl;
  return 0;
}
