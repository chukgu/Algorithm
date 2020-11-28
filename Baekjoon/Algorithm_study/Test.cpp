#include <stdio.h>
#include <iostream>
using namespace std;
//swap: �迭���v[i] ��v[j]�ǰ����ٲ�
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

//qsort: �迭���v[left]����v[right] ������ ���� ������������ ����
void qsort(int v[], int left, int right)
{
	int i, last;
	int j;
	void swap(int v[], int i, int j);//����

	if (left >= right)//�ʿ���°�
		return;

	cout << "swap : " << v[left] << " " << v[(left + right) / 2] << endl;
	swap(v, left, (left + right) / 2);//����
	for (int k = 0; k < 10; k++) {
		cout << v[k] << " ";
	}
	cout << endl;

	last = left;
	for (i = left + 1; i <= right; i++) {
		if (v[i] < v[left]) {
			cout << "swap in for loop : " << v[last+1] << " " << v[i] << endl;
			swap(v, ++last, i);
			for (int k = 0; k < 10; k++) {
				cout << v[k] << " ";
			}
			cout << endl;
		}
	}

	cout << endl << endl;
	swap(v, left, last);
	cout << "qsort : left : " << v[left] << " " << v[last - 1] << endl;
	qsort(v, left, last - 1);
	cout << "qsort : right : " << v[last+1] << " " << v[right] << endl;
	qsort(v, last + 1, right);
}

int main()
{
	int i;
	int v[] = { 2, 9, 4, 7, 6, 7, 5, 8, 3, 1 };

	qsort(v, 0, 9);

	for (i = 0; i < 9; i++)
		printf("%d, ", v[i]);
	printf("%d", v[i]);
}