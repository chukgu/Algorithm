#include <iostream>
#include <string>
#include <algorithm>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int gcd(int n, int m) {
	if (m == 0) {
		return n;
	}
	return gcd(m, n%m);
}

int main()
{
	int m,n,p[100];
	scanf("%i", &m);
	for (int i = 0; i < m; i++) {
		scanf("%i", &n);
		for (int j = 0; j < n; j++) {
			scanf("%i", &p[j]);
		}
		int ans=0;
		for (int j = 0; j < n-1; j++) {
			for (int k = j+1; k < n; k++) {
				//cout << p[j] << " " << p[k] << endl;
				ans+=gcd(p[j], p[k]);
			}
		}
		printf("%i\n", ans);
	}
}