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
		q_back = 1;
	}
	void push_front(int input) {
		q_size += 1;
		if (q_front + 1 == 0) {
			q_front = 9999;
			data[q_front--] = input;
		}
		else {
			data[q_front--] = input;
		}
	}
	void push_back(int input) {
		q_size += 1;
		if (q_back - 1 == 9999) {
			q_back = 0;
			data[q_back++] = input;
		}
		else {
			data[q_back++] = input;
		}
	}
	int pop_front() {
		if (q_size > 0) {
			q_size -= 1;
			if (q_front + 1 == 10000) {
				q_front = -1;
				return data[++q_front];
			}
			return data[++q_front];
		}
		else {
			return -1;
		}
	}
	int pop_back() {
		if (q_size > 0) {
			q_size -= 1;
			if (q_back - 1 == -1) {
				q_back = 10000;
				return data[--q_back];
			}
			return data[--q_back];
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
			if (q_back - 1 == -1) {
				return data[9999];
			}
			return data[q_back - 1];
		}
		else {
			return -1;
		}
	}
	int front() {
		if (q_size > 0) {
			if (q_front + 1 == 10000) {
				return data[0];
			}
			return data[q_front + 1];
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
		char c[15];
		scanf("%s", c);
		if (strcmp(c, "push_back") == 0) {
			scanf("%i", &n);
			s.push_back(n);
		}
		else if (strcmp(c, "push_front") == 0) {
			scanf("%i", &n);
			s.push_front(n);
		}
		else if (strcmp(c, "pop_front") == 0) {
			cout << s.pop_front() << endl;
		}
		else if (strcmp(c, "pop_back") == 0) {
			cout << s.pop_back() << endl;
		}
		else if (strcmp(c, "size") == 0) {
			cout << s.size() << endl;
		}
		else if (strcmp(c, "empty") == 0) {
			cout << s.empty() << endl;
		}
		else if (strcmp(c, "front") == 0) {
			cout << s.front() << endl;
		}
		else if (strcmp(c, "back") == 0) {
			cout << s.back() << endl;
		}
		while (getchar() != '\n');
	}
	return 0;
}