#include <iostream>
#include <math.h>
using namespace std;

void comp_mid(int arr[], int *cnt) {
	if (abs(arr[1] - arr[0]) < abs(arr[1] - arr[2])) {
		int tmp = arr[1];
		arr[0] = tmp;
		arr[1] = tmp + 1;
		if (arr[1] == arr[2]) {
			arr[1] = -1;
			return;
		}
		*cnt += 1;
		return;
	}
	else {
		int tmp = arr[1];
		arr[2] = tmp;
		arr[1] = tmp - 1;
		if (arr[1] == arr[0]) {
			arr[1] = -1;
			return;
		}
		*cnt += 1;
		return;
	}
}
void num_sort(int arr[]) {
	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int main() {
	int arr[3] = { 0, };
	cin >> arr[0] >> arr[1] >> arr[2];
	int cnt = 0;
	num_sort(arr);
	int count = 0;

	while (arr[1] >= 0) {
		comp_mid(arr, &cnt);
	}
	cout << cnt;
	return 0;
}