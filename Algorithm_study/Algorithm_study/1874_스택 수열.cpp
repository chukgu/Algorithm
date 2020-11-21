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
	char queue[200000];
	int stack[100000],st_idx=0,q_idx=0;
	int cur = 1,n,m;

	scanf("%i", &m);
	for (int i = 0; i < m; i++) {
		scanf("%i", &n);

		while (cur <= n) {
			stack[st_idx++] = cur;
			queue[q_idx++] = '+';
			cur++;
		}
		if (stack[st_idx-1] == n) {
			st_idx--;
			queue[q_idx++] = '-';
		}
		else {
			cur = 0;
			break;
		}
	}
	if (cur != 0) {
		for (int i = 0; i < q_idx; i++) {
			cout << queue[i] << '\n';
		}
	}
	else {
		printf("NO\n");
	}
	return 0;
}
