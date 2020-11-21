#include <iostream>
#include <algorithm>

using namespace std;

int d[100];
int f(int n) {
	if (n <= 1) {
		return n;
	}
	else {
		if (d[n] > 0) {
			return d[n];
		}
		d[n] = f(n - 1) + f(n - 2);
		return d[n];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int m, n;
	scanf("%i", &m);
	for (int i = 0; i < m; i++) {
		scanf("%i", &n);
		if (n == 0) printf("1 0\n");
		else printf("%i %i\n", f(n - 1), f(n));
	}
	return 0;
}