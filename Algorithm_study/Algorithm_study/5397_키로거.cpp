#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> s1, s2;
int T;
int main() {
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		for (int i = 0; s[i]; i++) {
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
				s1.push(s[i]);
			}
			if (s[i] == '<' && !s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
			if (s[i] == '>' && !s2.empty()) {
				s1.push(s2.top());
				s2.pop();
			}
			if (s[i] == '-' && !s1.empty()) {
				s1.pop();
			}
		}
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		while (!s2.empty()) {
			cout << s2.top();
			s2.pop();
		}
		cout << "\n";
	}
}