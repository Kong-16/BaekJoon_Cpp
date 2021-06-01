#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 100001
using namespace std;

int arr[MAX];

int histogram(int s, int e) {
	if (s == e) return 0;
	if (s + 1 == e) return arr[s];

	int mid = (s + e) / 2;
	int res = max(histogram(s, mid), histogram(mid, e));

	int width = 1, height = arr[mid], left = mid, right = mid;
	while (right - left + 1 < e - s) {
		int a = left > s ? min(height, arr[left - 1]) : 0;
		int b = right < e ? min(height, arr[right + 1]) : 0;
		if (a >= b) height = a, left--;
		else height = b, right++;
		res = max(res, ++width * height);
	}
	return res;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cout << histogram(0, N);
}