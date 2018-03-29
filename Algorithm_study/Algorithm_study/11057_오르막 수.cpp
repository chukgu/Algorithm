#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int d[1001][10] = { 0, };
//int p[10001];

int main()
{
	for (int i = 0; i <= 9; i++) {
		d[1][i] = 1;
	}
	int m;
	scanf("%i", &m);
	for (int i = 2; i <= m; i++) {
		d[i][0] = 1;
		for (int j = 1; j <= 9; j++) {
			d[i][j] = d[i][j - 1] + d[i - 1][j];
			d[i][j] %= 10007;
		}
	}
	long long a = 0;
	for (int i = 0; i <= 9; i++) a += d[m][i];
	printf("%i\n", a % 10007);
	return 0;
}