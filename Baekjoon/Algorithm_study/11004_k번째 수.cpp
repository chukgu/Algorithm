#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

int a[5000000];
int main() {
	int n, k;
	scanf("%i %i", &n, &k);
	k -= 1;
	for (int i = 0; i < n; i++) {
		scanf("%i", &a[i]);
	}
	nth_element(a, a + k, a + n);
	printf("%i\n", a[k]);

	return 0;
}