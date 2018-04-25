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

struct Person {
	int age;
	string name;
	//가입 날짜가 필요 없어짐. -stable sort니까
};
bool cmp(const Person &u, const Person &v) {
	return u.age < v.age;
}
int main() {
	int n;
	cin >> n;

	vector<Person> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].age >> a[i].name;
	}

	stable_sort(a.begin(), a.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << a[i].age << ' ' << a[i].name << '\n';
	}

	return 0;
}