#include <iostream>
using namespace std;
int main()
{
	int a, b;
	/*while (cin >> a >> b) {
	cout << a + b << endl;
	}*/
	while (scanf("%i %i", &a, &b) == 2) {
		printf("%i\n", a + b);
	}
}