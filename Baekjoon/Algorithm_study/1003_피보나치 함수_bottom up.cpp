#include <iostream>
#include <algorithm>

using namespace std;

int d[42] = { 0,1 };

int main() {
	ios_base::sync_with_stdio(false);
	int m, n;
	for (int i = 2; i < 41; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	scanf("%i", &m);
	for (int i = 0; i < m; i++) {
		scanf("%i", &n);
		if (n == 0) printf("1 0\n");
		else printf("%i %i\n", d[n - 1], d[n]);
	}
	return 0;
}