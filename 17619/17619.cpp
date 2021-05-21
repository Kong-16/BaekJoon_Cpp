#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int parent[100002];

int find(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (parent[a] > parent[b]) parent[a] = parent[b];
	else parent[b] = parent[a];

}

class oak_log {
public:
	int x1;
	int x2;
	int num;
};

bool cmp(oak_log& a, oak_log& b) {
	if (a.x1 == b.x1) return a.x2 < b.x2;
	return a.x1 < b.x1;
}



int main() {
	FASTIO;
	int N, Q;
	vector <oak_log> arr;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr.push_back({ a,b,i });
		parent[i] = i;
	}
	sort(arr.begin(), arr.begin() + N, cmp);
	int i = 0, j = 1;
	while(i < N && j < N) {
		if (arr[i].x2 >= arr[j].x1) {
			merge(arr[i].num, arr[j].num);
			j++;
		}
		else i++;
	}
	for (int i = 0; i < Q; i++) {
		int start, dest;
		cin >> start >> dest;
		if (find(start) == find(dest)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}