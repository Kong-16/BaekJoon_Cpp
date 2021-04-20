#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 1001

using namespace std;

int parent[MAX];
class Edge {
public:
	int start, end, weight;
	bool operator<(Edge& e) {
		return weight < e.weight;
	}
	
};
int find(int n) {
	if (parent[n] < 0) return n;
	return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (parent[a] > parent[b]) swap(a, b);
	parent[a] += parent[b];
	parent[b] = a;
}

bool isSameParent(int a, int b) {
	a = find(a);
	b = find(b);
	return a == b;
}

int main() {
	FASTIO;
	int n, m;
	vector<Edge> e;
	cin >> n >> m;
	for (int i = 0; i < n; i++) parent[i] = -1;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e.push_back({ a,b,c });
	}
	sort(e.begin(), e.end());
	int result = 0;
	for (int i = 0; i < m; i++) {
		if (!isSameParent(e[i].start, e[i].end)) {
			merge(e[i].start, e[i].end);
			result += e[i].weight;
		}
	}
	cout << result;
}