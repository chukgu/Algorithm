/*
	왜 안 되는지 모르겠음!!!!!(99프로에서 틀렸습니다! 나옴..)
*/

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

void reverseChar(char str[])
{
	int len = strlen(str);
	for (int i = 0; i<len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

int main()
{
	char s[30], c[30];
	string ans;
	scanf("%s", s);
	int s_len = strlen(s);
	scanf("%s", s+s_len);
	s_len = strlen(s);

	scanf("%s", c);
	int c_len = strlen(c);
	scanf("%s", c + c_len);
	c_len = strlen(c);

	//cout << s << " , " << c << endl;
	reverseChar(s);
	reverseChar(c);
	//cout << s << " , " << c << endl;

	int m = min(s_len, c_len);
	int x = 0;
	for (int i = 0; i < m; i++) {
		int temp = (s[i] - '0') + (c[i] - '0') + x;
		//cout << s[i] - '0' << " , " << c[i] - '0' << " : " << temp << endl;
		ans += char((temp % 10)+'0');
		x = 0;
		//cout << "ans : " << ans[i] << endl;
		if (temp >= 10) {
			x = 1;
		}
	}
	//cout << endl;
	int n = max(s_len, c_len);
	for (int i = m; i < n; i++) {
		if (c[i] < '0' || c[i] > '9') {
			c[i] = 0;
		}
		if (s[i] < '0' || s[i] > '9') {
			s[i] = 0;
		}
		//cout << " x :  " << x << endl;
		int temp = c[i] + s[i] + x - '0';
		//cout << s[i] << " , " << c[i] << " : " << temp << endl;
		ans += char(temp +'0');
		x = 0;
		if (temp >= 10) {
			x = 1;
		}
	}
	if (x == 1) {
		ans += char(x + '0');
	}
	//cout << ans << endl;
	reverse(ans.begin(), ans.end());
	//cout << ans << endl;
	long long a = stoll(ans);
	printf("%lli\n", a);
	return 0;
}

//14 488 2669 4298

//	2670 8786
// //(더 쉬운 방법)
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	string s1 = to_string(a) + to_string(b);
	string s2 = to_string(c) + to_string(d);

	long long l1 = stoll(s1);
	long long l2 = stoll(s2);

	cout << l1 + l2 << '\n';
	return 0;
}
*/
