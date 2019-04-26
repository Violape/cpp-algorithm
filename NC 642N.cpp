/*
	Source: Nowcoder 642A

	大美门口那棵树上的苹果有两种颜色：金和银。金苹果的数量是 n，每个苹果都有它的 id
	（id 从 1 到 n）和不同的重量（g[i]）。银苹果的数量是 n，每个苹果都有它的 id（id
	从 1 到 n）和不同的重量（s[i]）。现在你需要用这些苹果来串一条项链。第一个要求是
	项链的颜色必须是金银相间的（意思是一个金苹果接一个银苹果，一个银苹果接一个金苹果，
	一个接一个…）。第二个要求是项链中的所有金苹果的重量应该按降序排列，银苹果也是降
	序。你能告诉我这条项链的 id 吗？这条项链的 id 是构成这条项链的金苹果和银苹果的 
	id 组合。而且，第一个一定是金苹果。 

	第一行一个整数T(T <= 50)，表示数据组数。在每组输入数据中，第一行有一个正整数，
	n(n<= 1000)。第二行中有n个正整数g[i](g[i] <= 1000)，是n个金苹果的重量。第三行
	中有n个正整数s[i](s[i] <= 1000)，是n个银苹果的重量。

	对于每组数据，输出项链的id，每两个数中间有一个空格。

	input:
	2
	4
	1 2 3 4
	2 5 1 3
	5
	2 5 3 4 1
	1 2 3 4 5

	output:
	4 2 3 4 2 1 1 3
	2 5 4 4 3 3 1 2 5 1
*/
#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, g[1010], s[1010], gi[1010], si[1010];
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> g[i];
		for (int i = 0; i < n; i++)
			cin >> s[i];
		for (int i = 0; i < n; i++) {
			gi[i] = i;
			si[i] = i;
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - 1 - i; j++) {
				if (g[j] < g[j + 1]) {
					int temp = g[j];
					g[j] = g[j + 1];
					g[j + 1] = temp;
					temp = gi[j];
					gi[j] = gi[j + 1];
					gi[j + 1] = temp;
				}
				if (s[j] < s[j + 1]) {
					int temp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = temp;
					temp = si[j];
					si[j] = si[j + 1];
					si[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << gi[i] + 1 << " " << si[i] + 1;
			if (i != n - 1)
				cout << " ";
			else
				cout << endl;
		}
	}
	return 0;
}
