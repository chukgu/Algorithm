#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long d[91][2] = { 0, };

int main()
{
	d[1][0] = 0,d[1][1] = 1;
	int m;
	scanf("%i", &m);
	for (int i = 2; i <= m; i++) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	printf("%lli\n", d[m][0]+d[m][1]);
	return 0;
}