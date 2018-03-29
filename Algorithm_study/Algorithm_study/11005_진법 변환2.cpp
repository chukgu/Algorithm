#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int main()
{
	long long n;
	int m;
	int arr[100], num = 0;
	scanf("%lli%i", &n, &m);

	while (n != 0) {
		arr[num++] = n%m;
		n = n / m;
	}
	char ans[100];
	for (int i = num - 1; i >=0; i--) {
		if (arr[i] > 9) {
			ans[i] = char(arr[i]) + 'A' - 10;
		}
		else {
			ans[i] = char(arr[i]) + '0';
		}
		printf("%c", ans[i]);
	}
	printf("\n");
}
