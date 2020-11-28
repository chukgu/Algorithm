#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

int cnt[10001];
int main() {
	int n;
	scanf("%i", &n);

	int temp = 0;
	for (int i = 0; i < n; i++) {
		scanf("%i", &temp);
		cnt[temp] += 1;
	}

	for (int i = 1; i <= 10000; i++) {
		if (cnt[i] > 0) {
			for (int j = 0; j < cnt[i]; j++) {
				printf("%i\n", i);
			}
		}
	}
	return 0;
}

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int cnt[10001];
int main() {
	int n;
	scanf("%d", &n);
	int temp = 0;
	for (int i = 0; i<n; i++) {
		scanf("%d", &temp);
		cnt[temp] += 1;
	}
	for (int i = 1; i <= 10000; i++) {
		if (cnt[i] > 0) {
			for (int j = 0; j<cnt[i]; j++) {
				printf("%d\n", i);
			}
		}
	}

	return 0;
}
*/