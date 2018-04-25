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

int main() {
	int n;
	scanf("%i", &n);
	vector<pair<int, int>> a(n);

	for (int i = 0; i < n; i++) {
		scanf("%i %i", &a[i].first, &a[i].second);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		printf("%i %i\n", a[i].first, a[i].second);
	}
}

/*
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

int xy[2][100000];

int main()
{
	int m;
	scanf("%i", &m);
	for(int i = 0; i < m; i++) {
		scanf("%i %i", &xy[0][i], &xy[1][i]);
		
	}
	//x가 같으면 y만 바꿔도 됨.
	//입력을 받으면서 삽입!!! 정렬하기.
	for (int i = 0; i < m; i++) {
		printf("%i %i\n", xy[0][i], xy[1][i]);
	}
	return 0;
}
*/