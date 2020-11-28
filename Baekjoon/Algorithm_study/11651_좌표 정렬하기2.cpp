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
		scanf("%i %i", &a[i].second, &a[i].first);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		printf("%i %i\n", a[i].second, a[i].first);
	}
	return 0;
}