/*
  小Q的父母要出差N天，走之前给小Q留下了M块巧克力。
  小Q决定每天吃的巧克力数量不少于前一天吃的一半，但是他又不想在父母回来之前的某一天没有巧克力吃。
  请问他第一天最多能吃多少块巧克力。
  
  每个输入包含一个测试用例。
  每个测试用例的第一行包含两个正整数，表示父母出差的天数N(N<=50000)和巧克力的数量M(N<=M<=100000)。
  输出一个数表示小Q第一天最多能吃多少块巧克力。
*/

#include <iostream>
using namespace std;
int test(int b, int n) {
	int tot = 0;
	for (int i = 0; i < n; i++) {
		tot += b;
		b = (b + 1) / 2;
	}
	return tot;
}

int find(int l, int r, int n, int m) {
	int sol = (l + r) / 2;
	if (r - l < 2) {
		return sol;
	}
	int cal = test((l + r) / 2, n);
	if (cal > m)
		sol = find(l, (l + r) / 2, n, m);
	else if (cal == m)
		return (l + r) / 2;
	else
		sol = find((l + r) / 2, r, n, m);
	return sol;
}

int main() {
	int n, m;
	cin >> n >> m;
	if (n == 1)
		cout << m << endl;
	else
		cout << find(0, m, n, m) << endl;
	return 0;
}

// 二分法解决解接近n/2的问题
