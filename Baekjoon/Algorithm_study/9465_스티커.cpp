#include <iostream>
#include <string>
#include <algorithm>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

long long dp[100001][3];

int main()
{
	int T,m;
	scanf("%i", &T);
	while (T--) {
		int sticker[100001][2];
		int num = 0, n;
		scanf("%i", &m);
		while (num != 2) {
			for (int i = 1; i <= m; i++) {
				scanf("%i", &n);
				sticker[i][num] = n;
			}
			num++;
		}
		num = 0;
		dp[0][0] = 0, dp[0][1] = 0, dp[0][2] = 0;
		for (int i = 1; i <= m; i++) {
			dp[i][2] = max(dp[i-1][2],max(dp[i-1][0],dp[i-1][1]));
			dp[i][0] = max(dp[i - 1][2], dp[i - 1][1]) + sticker[i][0];
			dp[i][1] = max(dp[i - 1][2], dp[i - 1][0]) + sticker[i][1];
		}
		long long ans = max(dp[m][2], max(dp[m][0], dp[m][1]));
		printf("%lli\n", ans);
	}
	return 0;
}