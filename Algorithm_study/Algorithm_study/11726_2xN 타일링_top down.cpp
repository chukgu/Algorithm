#include <iostream>
#include <algorithm>

using namespace std;

int d[1001];

int f(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		if (d[n] > 0) {
			return d[n];
		}
		d[n] = (f(n - 1) + f(n - 2)) % 10007;
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