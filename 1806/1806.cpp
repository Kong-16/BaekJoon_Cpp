#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 100000001
using namespace std;

int main() {
	FASTIO;
	int N, S, num, start, end, sum ,ans;
	vector <int> v;
	
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	v.push_back(0);

	sum = v[0];
	start = end = 0;
	ans = MAX;

	while (start <= end && end < N) {
		if (sum < S) sum = sum + v[++end];
		
		else {
			ans = min(ans, end - start + 1);
			sum = sum - v[start++];
		}
	}

	if (ans == MAX)
		cout << 0;
	else
		cout << ans;
}