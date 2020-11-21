#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int main()
{
	string s;
	int m;
	long long ans=0;
	cin >> s >> m;
	int s_len = s.length();
	int c = 0,num=0;
	for (int i = s_len - 1; i >= 0; i--) {
		if ('A' <= s.at(i) && s.at(i) <= 'Z') {
			c = int(s.at(i)) - 'A' + 10;
		}
		else {
			c = int(s.at(i)) - '0';
		}
		ans += c*pow(m, num);
		num++;
	}
	printf("%lli\n", ans);
}
/*
더 빠르게
*/
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char n[100];
	int i, b, sum = 0;

	scanf("%s%i", n, &b);
	for (i = 0; i < strlen(n); i++) {
		if ('0' <= n[i] && n[i] <= '9') {
			sum = sum * b + (n[i] - '0');
		}
		else {
			sum = sum * b + (n[i] - 'A' + 10);
		}
	}
	printf("%i\n", sum);
}
*/
