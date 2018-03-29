#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stack>
#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int main()
{
	stack <char>s;
	char c[100001];
	int cnt = 0,ans=0;

	scanf("%s", c);
	for (int i = 0; c[i] != '\0'; i++) {
		if (c[i] == '(') {
			s.push(c[i]);
		}
		else {
			if (i!=1) {
				if (c[i - 1] == '(') {
					ans += s.size() - 1;
				}
				else {
					ans += 1;
				}
			}
			s.pop();
		}
	}
	printf("%i\n", ans);
	return 0;
}
/*
	((( () -> 3*1 = 3
	((( () -> 3*1 = 3
	(((  ) -> +1
	(( ()  -> 2*1 = 2  ... 이런식으로 다 더하면 됨.
	if (i!=1)은 예외처리
*/