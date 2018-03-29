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
	ans = dp[1];
	dp[1] = 1;
	for (int i = 2; i <= m; i++) {
		dp[i] = 1;
		for (int j = i-1; j >=1; j--) {
			if (p[j] < p[i] && dp[i] < dp[j]+1) {
				dp[i] = dp[j] + 1;
			}
		}
		//for (int j = 1; j < i; j++) {
		//	if (p[j] < p[i] && dp[i] < dp[j] + 1) {
		//		dp[i] = dp[j] + 1;
		//	}
		//}
		if (ans < dp[i]) {
			ans = dp[i];
		}
	}
	printf("%i\n", ans);
}
