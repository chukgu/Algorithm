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
	dp[1] = p[1];
	ans = dp[1];
	for (int i = 2; i <= m; i++) {
		dp[i] = p[i];
		for (int j = 1; j < i; j++) {
			if (p[j] < p[i] && dp[i] < dp[j]+p[i]) {
				dp[i] = dp[j] + p[i];
			}
		}
		if (ans < dp[i]) {
			ans = dp[i];
		}
	}
	printf("%i\n", ans);
}
