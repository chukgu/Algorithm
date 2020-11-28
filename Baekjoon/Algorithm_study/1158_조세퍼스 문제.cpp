#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

#define MAX 100000
class Queue {
private:
	int q_jose;
	int q_back;
	int q_size;
	int q_front;
	int data[MAX] = { -1, };
public:
	Queue() {
		q_jose = 0;
		q_size = 0;
		q_back = 0;
		q_front = 0;
	}
	void push(int input) {
		q_size += 1;
		if (q_back > MAX-1) {
			q_back = 0;
		}
		data[q_back++] = input;
	}
	int size() {
		return q_size;
	}
	int empty() {
		if (q_size == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int change() {
		if (q_size > 0) {
			q_size -= 1;
			if (q_front > MAX-1) {
				q_front = 0;
			}
			q_front += 1;
		}
		else {
			return -1;
		}
	}
	int jose(int x) {
		int k = q_front + x - 1;
		for (int i = q_front; i < k; i++) {
			int o = i;
			if (i > MAX-1) {
				o = o - MAX;
			}
			push(data[o]);
			data[o] = -1;
			change();
		}
		q_size -= 1;
		return data[q_front++];
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	Queue s;

	int m, n;
	scanf("%i %i", &m, &n);
	for (int i = 1; i <= m; i++) {
		s.push(i);
	}
	printf("<");
	while (s.empty() != 1) {
		if (s.size() == 1) {
			printf("%i>\n", s.jose(n));
			break;
		}
		printf("%i, ", s.jose(n));
	}
	return 0;
}