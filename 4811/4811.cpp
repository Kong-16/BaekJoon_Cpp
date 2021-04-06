#include <iostream>

using namespace std;

long long dp[33][33];

long long dfs(int W, int H) {
	if (dp[W][H]) return dp[W][H];
	if (W == 0) return 1;
	if (H > 0) dp[W][H] = dfs(W, H - 1) + dfs(W - 1, H + 1);
	else dp[W][H] = dfs(W - 1, H + 1);
	return dp[W][H];
}


int main() {
	int num;

	while (true) {
		cin >> num;
		if (num == 0) break;
		cout << dfs(num, 0) << endl;
	}
}