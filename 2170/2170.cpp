#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main() {
	FASTIO;
	int N, x, y, pre_left, pre_right, sum;

	vector <pair<int, int>> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.begin() + N);

	pre_left = v[0].first;
	pre_right = v[0].second;
	sum = 0;

	for (int i = 1; i < N; i++) {
		if (v[i].second <= pre_right) continue;
		if (v[i].first <= pre_right) pre_right = v[i].second;
		else {
			sum = sum + (pre_right - pre_left);
			pre_left = v[i].first;
			pre_right = v[i].second;
		}
	}
	sum = sum + (pre_right - pre_left);
	cout << sum;
}