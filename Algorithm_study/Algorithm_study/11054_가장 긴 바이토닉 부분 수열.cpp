#include <iostream>
#include <string>
#include <algorithm>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int dp[1001][2];
int p[1001];

int main()
{
	int m,ans;
	scanf("%i", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%i", &p[i]);
	}
	dp[1][0] = 1;
	dp[m][1] = 1;
	for (int i = 2; i <= m; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < i; j++) {
			if (p[j] < p[i] && dp[i][0] < dp[j][0] + 1) {
				dp[i][0] = dp[j][0] + 1;
			}
		}
	}
	ans = dp[m][0] + dp[m][1];
	for (int i = m - 1; i >= 1; i--) {
		dp[i][1] = 1;
		for (int j = m; j > i; j--) {
			if (p[j] < p[i] && dp[i][1] < dp[j][1] + 1) {
				dp[i][1] = dp[j][1] + 1;
			}
		}
		if (dp[i][0] + dp[i][1] > ans) {
			ans = dp[i][0] + dp[i][1];
		}
	}
	printf("%i\n", ans-1);
	return 0;
}
