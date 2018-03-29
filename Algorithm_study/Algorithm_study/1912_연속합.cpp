#include <iostream>
#include <string>
#include <algorithm>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int dp[100001];
int p[100001];

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
		int temp = p[i];
		dp[i] = p[i];
		for (int j = i-1; j >=1; j--) {
			temp += p[j];
			if (dp[i] < temp) {
				dp[i] = temp;
			}
		}
		if (ans < dp[i]) {
			ans = dp[i];
		}
	}
	printf("%i\n",ans);
	return 0;
}
/*
더 빠른 알고리즘
*/
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
	}
	vector<int> d(n);
	for (int i = 0; i<n; i++) {
		d[i] = a[i];
		if (i == 0) continue;
		if (d[i] < d[i - 1] + a[i]) {
			d[i] = d[i - 1] + a[i];
		}
	}
	int ans = d[0];
	for (int i = 1; i<n; i++) {
		if (ans < d[i]) {
			ans = d[i];
		}
	}
	cout << ans << '\n';
	return 0;

}
*/
