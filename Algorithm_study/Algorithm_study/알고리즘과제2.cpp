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
	int V, E, S, T;
	cin >> V >> E >> S >> T;

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
	dist[S - 1] = 0;

	for (int j = 1; j <= V - 1; j++) {
		for (int i = 0; i < E; i++) {
			int u = len[i].get_s() - 1;
			int v = len[i].get_d() - 1;
			int w = len[i].get_w();
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
			}
		}
	}

	cout << dist[T - 1] << "\n";
}
