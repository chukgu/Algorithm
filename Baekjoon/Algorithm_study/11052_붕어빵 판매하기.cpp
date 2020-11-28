#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int d[1001];
int p[10001];

int main()
{
	int m,n;
	d[0] = 0;
	scanf("%i", &m);
	for (int x = 1; x <= m; x++) {
		scanf("%i", &n);
		p[x] = n;
		d[x] = p[x];
		for (int i = 1; i < x; i++) {
			if (d[x] < (d[i] + p[x - i])) {
				d[x] = d[i] + p[x - i];
			}
		}
	}
	printf("%i\n", d[m]);
	return 0;
}