#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Queue {
private:
	int q_front;
	int q_back;
	int q_size;
	int data[10000];
public:
	Queue() {
		q_size = 0;
		q_front = 0;
		q_back = 0;
	}
	void push(int input) {
		q_size += 1;
		data[q_back++] = input;
	}
	int pop() {
		if (q_size > 0) {
			q_size -= 1;
			return data[q_front++];
		}
		else {
			return -1;
		}
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
	int back() {
		if (q_size > 0) {
			return data[q_back - 1];
		}
		else {
			return -1;
		}
	}
	int front() {
		if (q_size > 0) {
			return data[q_front];
		}
		else {
			return -1;
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	Queue s;

	int m;
	scanf("%i", &m);
	for (int i = 0; i < m; i++) {
		int n;
		char c[10];
		scanf("%s", c);
		if (strcmp(c, "push") == 0) {
			scanf("%i", &n);
			s.push(n);
		}
		else if (strcmp(c, "back") == 0) {
			cout << s.back() << endl;
		}
		else if (strcmp(c, "front") == 0) {
			cout << s.front() << endl;
		}
		else if (strcmp(c, "size") == 0) {
			cout << s.size() << endl;
		}
		else if (strcmp(c, "empty") == 0) {
			cout << s.empty() << endl;
		}
		else if (strcmp(c, "pop") == 0) {
			cout << s.pop() << endl;
		}
		while (getchar() != '\n');
	}
	return 0;
}