#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int d[101][10];
//int p[10001];

int main()
{
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}
	int m;
	scanf("%i", &m);
	for (int i = 2; i <= m; i++) {
		for (int j = 0; j <= 9; j++) {
			d[i][j] = 0;
			if (j > 0) d[i][j] += d[i - 1][j - 1];
			if (j < 9) d[i][j] += d[i - 1][j + 1];
			d[i][j] %= 1000000000;
		}
	}
	long long a = 0;
	for (int i = 0; i <= 9; i++) a += d[m][i];
	printf("%i\n", a%1000000000);
	return 0;
}