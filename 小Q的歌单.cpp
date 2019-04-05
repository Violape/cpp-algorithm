/*
  小Q有X首长度为A的不同的歌和Y首长度为B的不同的歌，现在小Q想用这些歌组成一个总长度正好为K的歌单，每首歌最多只能在歌单中出现一次，在不考虑歌单内歌曲的先后顺序的情况下，请问有多少种组成歌单的方法。
  
  每个输入包含一个测试用例。
  每个测试用例的第一行包含一个整数，表示歌单的总长度K(1<=K<=1000)。
  接下来的一行包含四个正整数，分别表示歌的第一种长度A(A<=10)和数量X(X<=100)以及歌的第二种长度B(B<=10)和数量Y(Y<=100)。保证A不等于B。
  输出一个整数,表示组成歌单的方法取模。因为答案可能会很大,输出对1000000007取模的结果。
*/

#include <iostream>
using namespace std;

long long c[101][101];
void cmb()
{
	c[0][0] = 1;
	for (int i = 1; i < 101; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 1000000007;
	}
}

int main() {
	int k, a, x, b, y;
	cin >> k;
	cin >> a >> x >> b >> y;
	cmb();
	if (b > a) {
		int temp = b; b = a; a = temp;
		temp = x; x = y; y = temp;
	}
	int inst = k / a;
	if (inst > x)
		inst = x;
	long long sol = 0;
	for (int i = 0; i <= inst; i++) {
		if ((k - i * a) / b <= y && (k - i * a) % b == 0) {
			long long finda = c[x][i];
			long long findb = c[y][(k - i * a) / b];
			sol = (sol + (finda*findb)) % 1000000007;
		}
	}
	cout << sol << endl;
	return 0;
}

//打表求组合数
//求组合数采用动态规划思想
