#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int main()
{
	char c[101];
	int ans[26] = { 0, };
	scanf("%s", c);
	int c_len = strlen(c);
	for (int i = 0; i < c_len; i++) {
		ans[c[i] - 'a'] += 1;
	}
	for (int i = 0; i < 26; i++) {
		printf("%i ", ans[i]);
	}
	printf("\n");
	return 0;
}