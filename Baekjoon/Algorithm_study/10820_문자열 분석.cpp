#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	string c;
	while (getline(cin, c)) {
		//scanf("%[^\n]\n", c);
		int m = 0, n = 0, o = 0, p = 0;
		for (int i = 0; c[i]; i++) {
			if (c[i] >= 'a' && c[i] <= 'z') {
				m += 1;
			}
			else if (c[i] >= 'A' && c[i] <= 'Z') {
				n += 1;
			}
			else if (c[i] >= '0' && c[i] <= '9') {
				o += 1;
			}
			else if (c[i] == ' ') {
				p += 1;
			}
		}
		printf("%i %i %i %i\n", m, n, o, p);
		//while (getchar() != '\n');
	}
	return 0;
}