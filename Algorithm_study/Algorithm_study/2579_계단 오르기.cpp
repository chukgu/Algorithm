#include <iostream>
#include <string>
#include <algorithm>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int dp[301][3];
int p[301];

int main()
{
	int m;
	scanf("%i", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%i", &p[i]);
	}
	dp[1][0] = 0, dp[1][1] = p[1];
	for (int i = 2; i <= m; i++) {
		if (i == m) {
			dp[i][1] = dp[i - 1][0] + p[i];
			dp[i][2] = dp[i - 1][1] + p[i];
			break;
		}
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + p[i];
		dp[i][2] = dp[i - 1][1] + p[i];
	}
	
	printf("%i\n", max(dp[m][1], dp[m][2]));
	return 0;
}