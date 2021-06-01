#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int num[200001];
int cnt[200002];

int main() {
	FASTIO;
	
	int N, K, start, end, ans;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	memset(cnt, 0, sizeof(cnt));
	ans = start = end = 0;
	cnt[num[end]]++;
	while(start <= end && end < N) {
		if (cnt[num[end]] > K) {
			cnt[num[start]]--;
			start++;
		}
		else {
			ans = max(ans, end - start + 1);
			end++;
			cnt[num[end]]++;
		}
	}

	cout << ans;
}