#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 300001
using namespace std;

bool in[MAX];
int parent[MAX];

int find(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	parent[a] = b;
}
int main() {
	FASTIO;
	int n, l;
	cin >> n >> l;
	for (int i = 1; i <= l; i++) parent[i] = i;
	
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (!in[a]) {
			in[a] = true;
			merge(a, b);
			cout << "LADICA\n";
		}
		else if (!in[b]) {
			in[b] = true;
			merge(b, a);
			cout << "LADICA\n";
		}
		else if (!in[find(a)]) {
			in[find(a)] = true;
			merge(a, b);
			cout << "LADICA\n";
		}
		else if (!in[find(b)]) {
			in[find(b)] = true;
			merge(b, a);
			cout << "LADICA\n";
		}
		else
			cout << "SMECE\n";
	}
}