#include <stdio.h>
#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

template<typename T>
class st {
private:
	int s_top;
	T data[51];
public:
	st() {
		s_top = 0;
	}
	void push(T in) {
		data[s_top++] = in;
	}
	T pop() {
		if (s_top > 0) {
			return data[--s_top];
		}
		else {
			return -1;
		}
	}
	void init() {
		//printf("스택 비우기: \n");
		s_top = 0;
	}
	//void print() {
	//	printf("스택에 남은 것: ");
	//	for (int i = 0; i < s_top; i++) {
	//		printf("%c", data[i]);
	//	}
	//	cout << endl;
	//}
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
	T top() {
		if (s_top > 0) {
			return data[s_top - 1];
		}
		else {
			return -1;
		}
	}
};

int main() {
	//std::ios_base::sync_with_stdio(false);
	st <char>s;

	int m;
	scanf("%i", &m);
	for (int i = 0; i < m; i++) {
		int x = 0;
		char c[50];
		scanf("%s", c);
		s.init();
		for (int i = 0; c[i] != '\0'; i++) {
			if (c[i] == '(') {
				s.push(c[i]);
			}
			else {
				if (s.top() == -1) {
					printf("NO\n");
					x = 1;
					break;
				}
				s.pop();
			}
		}
		if (x == 0) {
			if (s.top() != -1) {
				printf("NO\n");
			}
			else {
				printf("YES\n");
			}
		}
	}
	return 0;
}