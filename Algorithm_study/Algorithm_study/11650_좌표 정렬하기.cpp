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
	//x�� ������ y�� �ٲ㵵 ��.
	//�Է��� �����鼭 ����!!! �����ϱ�.
	for (int i = 0; i < m; i++) {
		printf("%i %i\n", xy[0][i], xy[1][i]);
	}
	return 0;
}