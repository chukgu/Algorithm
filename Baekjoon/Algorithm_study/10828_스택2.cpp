#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Stack {
private:
	int s_top;
	int data[10000];
public:
	Stack() {
		s_top = 0;
	}
	void push(int input) {
		data[s_top++] = input;
	}
	int pop() {
		if (s_top > 0) {
			return data[--s_top];
		}
		else {
			return -1;
		}
	}
	int size() {
		return s_top;
	}
	int empty() {
		if (s_top == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int top() {
		if (s_top > 0) {
			return data[s_top - 1];
		}
		else {
			return -1;
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	Stack s;

	int m, n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string c;
		cin >> c;
		if (c == "push") {
			cin >> n;
			s.push(n);
		}
		else if (c == "top") {
			cout << s.top() << endl;
		}
		else if (c == "size") {
			cout << s.size() << endl;
		}
		else if (c == "empty") {
			cout << s.empty() << endl;
		}
		else if (c == "pop") {
			cout << s.pop() << endl;
		}
	}
	return 0;
}