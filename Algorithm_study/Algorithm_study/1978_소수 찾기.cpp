#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int sosu(int num) {
	if (num <= 1) {
		return -1;
	}
	for (int i = 2; i*i <= num; i++) {
		if (num % i == 0) {
			return -1;
		}
	}
	return 1;
}

int main()
{
	int num;
	int in;
	int cnt = 0;

	scanf("%i", &in);

	for (int i = 0; i < in; i++) {
		scanf("%i", &num);
		if (sosu(num) == 1) {
			cnt++;
		}
	}
	printf("%i", cnt);
}
