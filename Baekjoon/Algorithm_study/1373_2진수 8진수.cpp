#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
char c[10000003] = { '0','0' };
int main()
{
	scanf("%s", c+2);//3���� ��� �Ϸ���(���̵� 2 �þ)
	int c_len = strlen(c);
	for (int i = c_len % 3; i < c_len; i = i + 3) {
		printf("%i", (c[i] - '0') * 4 + (c[i + 1] - '0') * 2 + (c[i + 2] - '0'));
	}
	printf("\n");
}
/*
	���ڷθ� �ذ��غ����� �ߴµ�, �Է��� 100���� �ƴ϶� 100�� �ڸ�����������..
	��Ÿ�� ����..
*/
/*
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int main()
{
	unsigned long long int n, ans = 0;
	int arr[10001], cnt = 0;
	scanf("%lli", &n);
	while (n != 0) {
		arr[cnt++] = n % 1000;
		n = n / 1000;
	}
	int num = 0;
	for (int i = 0; i < cnt; i++) {
		num = 0;
		while (arr[i] != 0) {
			int temp = arr[i] % 10;
			arr[i] = arr[i] / 10;
			if (temp == 1) {
				ans += temp*pow(2, num)*pow(10, i);
			}
			num++;
		}
	}
	cout << ans << endl;

	return 0;
}
*/