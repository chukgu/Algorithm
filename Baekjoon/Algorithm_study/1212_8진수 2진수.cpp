#include <iostream>
#include <string>
#include <string.h>
//#include <algorithm>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
//#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
char c[333350] = { '0','0' };
int main()
{
	scanf("%s", c);

	int c_len = strlen(c);
	for (int i = 0; i < c_len; i++) {
		int temp = c[i] - '0';
		int cnt = 0;
		char s[4];
		while (temp != 0) {
			s[cnt++] = (temp%2) + '0';
			temp = temp / 2;
		}
		if (i != 0) {
			while (cnt != 3) {
				s[cnt++] = '0';
			}
		}
		else {
			if (c[i] - '0' == 0) {
				cout << 0 << endl;
				return 0;
			}
		}
		while (cnt != 0) {
			cout << s[--cnt];
		}
	}
	cout << '\n';
	return 0;
}