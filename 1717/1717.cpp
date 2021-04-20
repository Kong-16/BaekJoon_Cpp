#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAX 1000001
using namespace std;

int parent[MAX];
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

int main() {
	FASTIO;
	int n, m;
	cin >> n >> m; 
	for (int i = 0; i <= n; i++) parent[i] = -1;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			if (find(b) == find(c))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		if (a == 0) {
			merge(b, c);
		}
	}
}