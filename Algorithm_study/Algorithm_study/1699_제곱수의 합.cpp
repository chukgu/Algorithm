#include <iostream>
#include <string>
#include <algorithm>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

int d[100001] = { 0, };

int main()
{
	int T;
	scanf("%i", &T);

	for (int i = 1; i <= T; i++) {
		d[i] = i;
		for (int j = 1; j*j <= i; j++) {
			if (d[i] > d[i - j * j] + 1) {
				d[i] = d[i - j * j] + 1;
			}
		}
	}
	printf("%i\n", d[T]);

	return 0;
}