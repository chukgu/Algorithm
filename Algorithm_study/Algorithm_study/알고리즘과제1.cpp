#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

void insertionsort(int arr[], int end) {
	cout << "insert : " << end << endl;
	int temp;
	if (end < 1) return;
	for(int i=1; i< end; i++){
		int j = i;
		temp = arr[i];
		while (j > 0 && arr[j - 1] > temp) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
	return;
}

void merge(int arr[], int left[], int right[], int lnum, int rnum) {
	int s = 0, i,j;
	for (i = 0, j = 0; i < lnum && j < rnum;) {
		if (left[i] < right[j]) {
			arr[s++] = left[i++];
		}
		else {
			arr[s++] = right[j++];
		}
	}
	for (; i < lnum; i++) {
		arr[s++] = left[i];
	}
	for (; j < rnum; j++) {
		arr[s++] = right[j];
	}
}

void merge_sort(int arr[], int end) {
	int mid = end / 2;
	int *left = new int[mid];
	int *right = new int[end - mid];

	if (end <= 1) {
		return;
	}
	int i;
	for (i = 0; i < mid; i++) {
		left[i] = arr[i];
	}
	for (; i < end; ++i) {
		right[i-mid] = arr[i];
	}
	
	if (mid <= 32) {
		insertionsort(left, mid);
	}
	else {
		cout << "			merge left: " << mid << endl;
		merge_sort(left, mid);
	}
	if (end - mid <= 32) {
		insertionsort(right, end-mid);
	}
	else {
		cout << "					merge right: " << end-mid << endl;
		merge_sort(right, end - mid);
	}
	merge(arr, left, right , mid, end-mid);
}

int main()
{
	int T;
	scanf("%i", &T);
	int a[10001];
	for (int i = 0; i < T; i++) {
		scanf("%i", &a[i]);
	}
	if (T > 32) {
		merge_sort(a, T);
	}
	else {
		insertionsort(a, T);
	}
	for (int i = 0; i < T; i++) {
		printf("%i ", a[i]);
	}
	printf("\n");

	/*for (int i = 0; i < 200; i++) {
		cout << rand() % 1000 + 1 << " ";
	}
	cout << endl;*/
	return 0;
}