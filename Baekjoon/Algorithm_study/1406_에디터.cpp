#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Editor {
private:
	int cursor;
	char data[600000];
public:
	Editor() {
		cursor = 0;
	}
	void push(char in) {
		data[cursor++] = in;
	}
	char cursor_move() {
		return data[--cursor];
	}
	int get_cursor() {
		return cursor;
	}
	void l_print() {
		for (int i = 0; i < cursor; i++) {
			cout << data[i];
		}
	}
	void r_print() {
		for (int i = cursor; i >0; i--) {
			cout << data[i - 1];
		}
		cout << endl;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	Editor s[2];

	char ch[100000];
	scanf("%s", ch);
	int len_ch = strlen(ch);
	for (int i = 0; i < len_ch; i++) {
		s[0].push(ch[i]);
	}

	int m;
	scanf("%i", &m);
	for (int i = 0; i < m; i++) {
		char c[10];
		scanf("%s", c);
		if (strcmp(c, "P") == 0) {
			char x;
			scanf(" %c", &x);
			s[0].push(x);
		}
		else if (strcmp(c, "L") == 0) {
			//cout << "L : " << s[0].get_cursor() << endl;
			if (s[0].get_cursor() != 0) {
				s[1].push(s[0].cursor_move());
			}
		}
		else if (strcmp(c, "D") == 0) {
			//cout << "D : " << s[1].get_cursor() << endl;
			if (s[1].get_cursor() != 0) {
				s[0].push(s[1].cursor_move());
			}
		}
		else if (strcmp(c, "B") == 0) {
			//cout << "B : " << s[0].get_cursor() << endl;
			if (s[0].get_cursor() != 0) {
				s[0].cursor_move();
			}
		}
		while (getchar() != '\n');
	}
	s[0].l_print();
	s[1].r_print();
	return 0;
}