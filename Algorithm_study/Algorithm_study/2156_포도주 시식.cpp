#include <iostream>
#include <string>
#include <algorithm>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int dp[10001][3];
int p[10001];

int main()
{
	int T;
	scanf("%i", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%i", &p[i]);
	}
	dp[1][0] = 0, dp[1][1] = p[1];
	for (int i = 2; i <= T; i++) {
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
		dp[i][1] = dp[i - 1][0] + p[i];
		dp[i][2] = dp[i - 1][1] + p[i];
	}
	printf("%i\n", max(dp[T][0], max(dp[T][1], dp[T][2])));
	return 0;
}

//#include <iostream>
//#include <string>
//#include <algorithm>
//#define max(a,b) (((a)>(b))?(a):(b))
//using namespace std;
//
//int dp[10001];
//int p[10001];
//
//int main()
//{
//	int T;
//	scanf("%i", &T);
//	for (int i = 1; i <= T; i++) {
//		scanf("%i", &p[i]);
//	}
//	dp[0] = 0,dp[1] = p[1], dp[2] = p[1] + p[2];
//	for (int i = 3; i <= T; i++) {
//		dp[i] = max(dp[i - 1], max(dp[i - 2] + p[i], dp[i - 3] + p[i - 1] + p[i]));
//	}
//	printf("%i\n", dp[T]);
//	return 0;
//}