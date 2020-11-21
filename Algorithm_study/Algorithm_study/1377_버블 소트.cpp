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

int main() {
	int n;
	scanf("%i", &n);
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%i", &a[i].first);
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		//original - changed
		if (ans < a[i].second - i) {
			ans = a[i].second - i;
		}
	}
	printf("%i\n", ans + 1);

	return 0;
}