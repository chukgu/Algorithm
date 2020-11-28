#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

#define MAX 1000000

using namespace std;

class edge {
private:
	int start;
	int dest;
	int weight;
public:
	void set_edge(int s, int d, int w) {
		start = s;
		dest = d;
		weight = w;
	}
	int get_s() {
		return start;
	}
	int get_d() {
		return dest;
	}
	int get_w() {
		return weight;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	int V, E;
	cin >> V >> E;

	int *dist = new int[V];

	edge *len = new edge[E];

	for (int i = 0; i < E; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		len[i].set_edge(x, y, z);
	}

	for (int i = 0; i < V; i++) {
		dist[i] = MAX;
	}
	dist[0] = 0;
	bool isNegCycle;
	for (int j = 1; j <= V; j++) {//1번 더 돌게 함(V-1 이 아니라 V 까지 - 한 번 더 돌면서 사이클 음수 확인)
		isNegCycle = false;
		for (int i = 0; i < E; i++) {
			int u = len[i].get_s() - 1;
			int v = len[i].get_d() - 1;
			int w = len[i].get_w();
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				isNegCycle = true;
			}
		}
	}

	if (isNegCycle == false) {
		for (int i = 1; i < V; i++) {
			if (dist[i] == MAX) cout << "-1\n";
			else cout << dist[i] << "\n";
		}
	}
	else cout << "-1\n";
}
