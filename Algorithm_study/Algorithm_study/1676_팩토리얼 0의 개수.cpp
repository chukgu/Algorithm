#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int main()
{
	int m,cnt=0;
	scanf("%i", &m);
	/*
	이 방법도 가능
	*/
	//for (int i = 5; i <= m; i *= 5) {
	//	cnt += m / i;
	//}
	cnt += m / 5;
	cnt += m / 25;
	cnt += m / 125;
	printf("%i\n", cnt);
}
/*
	일반적으로는 이 코드가 맞지만 20 이상 넘어가면 ans의 
	결과물조차 알 수가 없음.
	그래서 각각을 소인수분해 하면 0은 2x5일 때만 생기고
	2의 승수가 훨씬 많기 때문에
	5의 승수만 찾으면 된다
	(주의점으로는 25같은 경우는 5x5이기 때문에
	5가 2번 들어가게 된다.)
*/
/*
int main()
{
	int m;
	long long ans = 1;
	scanf("%i", &m);
	for (int i = 1; i <=m; i++) {
		ans *= i;
		//printf("%lli\n", ans);
	}
	printf("%lli\n", ans);
	int temp = 0,cnt =0;
	while (ans != 0 && temp == 0) {
		temp = ans % 10;
		ans = ans / 10;
		//cout << ans << " " << temp << endl;
		if (temp == 0) {
			cnt++;
		}
	}
	printf("%i\n", cnt);
}
*/