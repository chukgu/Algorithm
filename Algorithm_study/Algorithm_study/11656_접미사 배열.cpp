#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>  

#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

int main()
{
	string s,c[1001];
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		c[i] = s.substr(i);
	}
	sort(c, c + s.length());
	for (int i = 0; i < s.size(); i++) {
		cout << c[i] << endl;
	}
}