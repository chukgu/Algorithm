#include <iostream>
#include <algorithm>

using namespace std;

int d[1000001];
int f(int n) {
	if (n == 1) {
		return 0;
	}
	else {
		if (d[n] > 0) {
			return d[n];
		}
		d[n] = f(n - 1) + 1;
		if (n % 3 == 0) {
			int x = d[n / 3] + 1;
			if (d[n] > x) {
				d[n] = x;
			}
		}
		if (n % 2 == 0) {
			int x = d[n / 2] + 1;
			if (d[n] > x) {
				d[n] = x;
			}
		}
		return d[n];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int m;
	scanf("%i", &m);
	printf("%i\n", f(m));
	return 0;
}