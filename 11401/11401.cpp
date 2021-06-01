#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define DIVIDOR 100000000007
using namespace std;

int dp[4000000];
int factorial(int n) {
	if (dp[n]) return dp[n];
	if (n == 1) return 1;
	dp[n] = factorial(n - 1) * n;
	return dp[n];
}

int main() {
	FASTIO;
	int K, N, result;
	cin >> N >> K;
	result = factorial(N) % DIVIDOR * pow((factorial(K) * factorial(N - K)), DIVIDOR - 2) & DIVIDOR;

}