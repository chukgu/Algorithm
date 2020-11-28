#include <cstdio>
#include <string.h>

using namespace std;

int array[10000] = { 0, };
int count = 0;

void push() {
	int a;
	scanf("%i", &a);
	if (count == 0) {
		array[count] = a;
		//printf("array : %i\n", array[count]);
		count++;
	}
	else {
		array[count] = a;
		//printf("array : %i\n", array[count]);
		count++;
	}
}
void pop() {
	if (array[count - 1] > 0) {
		//printf("pop : %i\n", array[count-1]);
		printf("%i\n", array[count - 1]);
		array[count - 1] = 0;
		count--;
	}
	else {
		//printf("pop : -1\n");
		printf("-1\n");
	}
}
void size() {
	int j = 0;
	for (int i = 0; array[i] != 0; i++) {
		j++;
	}
	//printf("size : %i\n",j);
	printf("%i\n", j);
}
void empty() {
	int k = 0;
	for (int i = 0; array[i] != 0; i++) {
		k++;
	}
	if (k > 0) {
		//printf("empty : 0\n");
		printf("0\n");
	}
	else {
		//printf("empty : 1\n");
		printf("1\n");
	}
}
void top() {
	if (array[count - 1] > 0) {
		//printf("top : %i\n", array[count-1]);
		printf("%i\n", array[count - 1]);
	}
	else {
		//printf("top : -1\n");
		printf("-1\n");
	}
}
int main() {
	int num;
	char in[20];

	scanf("%i", &num);
	getchar();
	//printf("num: %i\n", num);
	while (num != 0) {
		num--;
		scanf("%s", in);
		if (strcmp(in, "push") == 0) {
			push();
		}
		else if (strcmp(in, "pop") == 0) {
			pop();
		}
		else if (strcmp(in, "size") == 0) {
			size();
		}
		else if (strcmp(in, "empty") == 0) {
			empty();
		}
		else if (strcmp(in, "top") == 0) {
			top();
		}
		//for (int i = 0; i<2; i++) {
		//	printf("   array[%i] : %i\n", i,array[i]);
		//}
		while (getchar() != '\n');
	}
	return 0;
}
