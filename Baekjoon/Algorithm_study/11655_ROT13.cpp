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
	scanf("%[^\n]\n", c);
	int c_len = strlen(c);
	for (int i = 0; i < c_len; i++) {
		if (c[i] >= 'A' && c[i] <= 'Z') {
			if (c[i] + 13 > 90) {
				c[i] = (c[i] + 13) % 90 + 64;
			}
			else {
				c[i] = c[i] + 13;
			}
		}
		else if(c[i] >= 'a' && c[i] <= 'z'){
			if (c[i] + 13 > 122) {
				c[i] = (c[i] + 13) % 122 + 96;
			}
			else {
				c[i] = c[i] + 13;
			}
		}
	}
	for (int i = 0; i < c_len; i++) {
		printf("%c", c[i]);
	}
	printf("\n");
	return 0;
}