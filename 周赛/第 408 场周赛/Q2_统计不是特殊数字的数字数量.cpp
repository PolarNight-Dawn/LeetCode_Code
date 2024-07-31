//
// Created by polarnight on 24-7-28, 上午11:01.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
 public:
  vector<int> Sieve(int n) {
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; ++i) {
	  if (is_prime[i]) {
		for (int j = i * i; j <= n; j += i) {
		  is_prime[j] = false;
		}
	  }
	}
	vector<int> primes;
	for (int i = 2; i <= n; ++i) {
	  if (is_prime[i]) {
		primes.push_back(i);
	  }
	}
	return primes;
  }

  bool isProperDivisors(int num, const vector<int> &primes) {
	int count = 0;
	for (int prime : primes) {
	  if (prime * prime > num) break;
	  if (num % prime == 0) {
		count++;
		if (num / prime != prime) count++;
	  }
	  if (count > 2) return false;
	}
	return count == 2;
  }

  int nonSpecialCount(int l, int r) {
	int max_num = r;
	vector<int> primes = Sieve(sqrt(max_num));
	int count = 0;
	for (int i = l; i <= r; ++i)
	  if (!isProperDivisors(i, primes))count++;
	return count;
  }
};

int main40802() {

}