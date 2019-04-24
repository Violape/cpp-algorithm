//返回相邻数的平均值
//输入：一个数n(数字个数)，n个数(源数据)
//输出: n个数(返回值)
//范围：2<=n<=1000, n个数<10000
#include <iostream>
using namespace std;
int main() {
	int n, a[1010], b[1010];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	b[0] = (a[0] + a[1]) / 2;
	for (int i = 1; i < n - 1; i++)
		b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3;
	b[n - 1] = (a[n - 2] + a[n - 1]) / 2;
	for (int i = 0; i < n; i++) {
		cout << b[i];
		if (i != n - 1)
			cout << " ";
	}
	return 0;
}
