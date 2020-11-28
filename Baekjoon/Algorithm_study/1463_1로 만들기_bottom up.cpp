#include <iostream>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int d[1000001];
//이건 내 방법이지만 밑의 코드가 더 좋음.
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	d[0] = 100000;
	d[1] = 0;
	scanf("%i", &n);
	for (int j = 2; j <= n; j++) {
		int x = 0, y = 0, z;
		if (j % 3 == 0) x = j / 3;
		if (j % 2 == 0) y = j / 2;
		z = j - 1;
		d[j] = min({ d[x], d[y], d[z] }) + 1;
		//cout << "dp[" << j << "] : " << dp[j] << endl;
	}
	printf("%i\n", d[n]);

	return 0;
}
//#include <iostream>
//#include <algorithm>
//#define _CRT_SECURE_NO_WARNINGS
//using namespace std;
//
//int dp[1000001];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	int n;
//	dp[1] = 0;
//	scanf("%i", &n);
//	for (int j = 2; j <= n; j++) {
//		dp[j] = dp[j - 1] + 1;
//		if (j % 3 == 0 && dp[j] > dp[j / 3] + 1) dp[j] = dp[j / 3] + 1;
//		if (j % 2 == 0 && dp[j] > dp[j / 2] + 1) dp[j] = dp[j / 2] + 1;
//	}
//	printf("%i\n", dp[n]);
//
//	return 0;
//}