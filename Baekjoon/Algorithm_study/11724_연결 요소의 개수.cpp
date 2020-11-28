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

vector<int> a[1001];
bool check[1001];
void dfs(int node) {
	check[node] = true;
	for (int i = 0; i<a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i<m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int components = 0;//BFS나 DFS 를 이용하기 때문에 다른 코드는 같지만
					   //연결 요소를 구해야 하기 때문에 모든 점에 대해서 한 번씩 실행해봐야 한다.
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			components += 1;
		}
	}
	printf("%d\n", components);
	return 0;
}