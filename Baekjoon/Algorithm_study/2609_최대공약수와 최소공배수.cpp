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
	int n, p;
	scanf("%i %i", &n, &p);
	int g = 0, a, b, ans = 0;
	g += gcd(n, p);
	a = n / g;
	b = p / g;
	ans = g*a*b;
	printf("%i\n%i\n", g,ans);
}