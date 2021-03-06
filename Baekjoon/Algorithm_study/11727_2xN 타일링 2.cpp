#include <iostream>
#include <algorithm>

using namespace std;

int d[1001] = { 1,1,3,};

int main() {
	ios_base::sync_with_stdio(false);
	int m;
	scanf("%i", &m);
	for (int i = 3; i <= m; i++) {
		d[i] = d[i - 1] + 2*d[i - 2];
		d[i] = d[i] % 10007;
	}
	printf("%i\n", d[m]);
	return 0;
}