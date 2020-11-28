#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N, K, M;
	scanf("%i %i %i", &N, &K, &M);

	int min = pow(2, M);
	int max = pow(2, N);
		
	if (min == 1 && K == max) {
		printf("-1\n");
		return 0;
	}
	if (K == max) {
		if (min == K) {
			printf("%i ", max);
			for (int i = 1; i < max; i++) {
				printf("%i ", i);
			}
			printf("\n");
		}
		else {
			printf("-1\n");
			return 0;
		}
	}
	else if (min <= K && K <= max) {
		printf("%i ", K);
		for (int i = 1; i < min; i++) printf("%i ", i);
		if (K != max) printf("%i ", max);
		for (int i = min; i < max; i++) {
			if (i == K) continue;
			printf("%i ", i);
		}
		printf("\n");
	}
	else {
		printf("-1\n");
		return 0;
	}
}
