/*
	Source: CodeForces 716B

	ZS the Coder loves to read the dictionary. He thinks that a word is nice if there exists a substring
	(contiguous segment of letters) of it of length 26 where each letter of English alphabet appears
	exactly once. In particular, if the string has length strictly less than 26, no such substring
	exists and thus it is not nice.
	Now, ZS the Coder tells you a word, where some of its letters are missing as he forgot them.
	He wants to determine if it is possible to fill in the missing letters so that the resulting word is
	nice. If it is possible, he needs you to find an example of such a word as well. Can you help him?

	The first and only line of the input contains a single string s (1 ≤ |s| ≤ 50 000), the word that ZS
	the Coder remembers. Each character of the string is the uppercase letter of English alphabet
	('A'-'Z') or is a question mark ('?'), where the question marks denotes the letters that ZS the
	Coder can't remember.

	If there is no way to replace all the question marks with uppercase letters such that the resulting
	word is nice, then print -1 in the only line.
	Otherwise, print a string which denotes a possible nice word that ZS the Coder learned. This string
	should match the string from the input, except for the question marks replaced with uppercase English
	letters.
	If there are multiple solutions, you may print any of them.

	Input: ABC??FGHIJK???OPQR?TUVWXY?
	Output: ABCDEFGHIJKLMNOPQRZTUVWXYS
	Input: WELCOMETOCODEFORCESROUNDTHREEHUNDREDANDSEVENTYTWO
	Output:-1
	Input:??????????????????????????
	Output:MNBVCXZLKJHGFDSAQPWOEIRUYT
	Input:AABCDEFGHIJKLMNOPQRSTUVW??M
	Output:-1
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
	string a;
	cin >> a;
	int n = a.length();
	if (n < 26) {
		cout << "-1" << endl;
		return 0;
	}
	int list[26];
	int fc = 1;
	for (int i = 0; i <= n - 26; i++) {
		int flag = 1;
		for (int j = 0; j < 26; j++) {
			list[j] = 0;
		}
		for (int j = 0; j < 26; j++) {
			char o = a.operator[](i + j);
			int pos = o - 'A';
			if (pos >= 0) {
				if (list[pos]) {
					flag = 0;
					break;
				}
				list[pos]++;
			}
		}
		if (flag) {
			for (int j = 0; j < i; j++) {
				char o = a.operator[](j);
				if (o == '?')
					cout << 'A';
				else
					cout << o;
			}
			int cnt = 0;
			for (int j = 0; j < 26; j++) {
				char o = a.operator[](i + j);
				if (o == '?') {
					for (int k = cnt; k < 26; k++) {
						if (list[k] == 0) {
							char op = 'A' + k;
							cout << op;
							cnt = k + 1;
							break;
						}
					}
				}
				else {
					cout << o;
				}
			}
			for (int j = i + 26; j < n; j++) {
				char o = a.operator[](j);
				if (o == '?')
					cout << 'A';
				else
					cout << o;
			}
			cout << endl;
			fc = 0;
			break;
		}
	}
	if (fc) {
		cout << "-1" << endl;
	}
	return 0;
}
