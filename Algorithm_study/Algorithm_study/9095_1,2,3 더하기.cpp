#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int d[13] = { 0,1,2,4, };

int main()
{
	int m;
	scanf("%i", &m);
	while (m--) {
		int n;
		scanf("%i", &n);
		for (int i = 4; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		printf("%i\n", d[n]);
	}
	return 0;
}