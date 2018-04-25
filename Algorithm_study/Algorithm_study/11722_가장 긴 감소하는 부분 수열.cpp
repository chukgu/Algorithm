#include <iostream>
#include <string>
#include <algorithm>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int dp[1001];
int p[1001];

int main()
{
	int m, ans;
	scanf("%i", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%i", &p[i]);
	}
	ans = 1;
	dp[m] = 1;
	for (int i = m - 1; i >= 1; i--) {
		dp[i] = 1;
		for (int j = m; j > i; j--) {
			if (p[j] < p[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		if (ans < dp[i]) {
			ans = dp[i];
		}
	}
	printf("%i\n", ans);
}