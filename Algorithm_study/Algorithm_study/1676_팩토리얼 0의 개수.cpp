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
	�� ����� ����
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
	�Ϲ������δ� �� �ڵ尡 ������ 20 �̻� �Ѿ�� ans�� 
	��������� �� ���� ����.
	�׷��� ������ ���μ����� �ϸ� 0�� 2x5�� ���� �����
	2�� �¼��� �ξ� ���� ������
	5�� �¼��� ã���� �ȴ�
	(���������δ� 25���� ���� 5x5�̱� ������
	5�� 2�� ���� �ȴ�.)
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