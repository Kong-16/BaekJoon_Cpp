#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int arr[303][22], dp[303][22], comp[303][22];
// arr[i][j] : i의 돈을 j회사에 넣었을 때의 수익
// dp[i][j] : i의 돈을 가지고 j번째 회사에 투자할 때 최대 수익금
// comp[i][j] : i의 돈으로 j번째 회사에 투자했을 때의 투자금

int dfs(int money, int num) {
	if (num > M) return 0; // 모든 회사 탐색하면 종료
	int& res = dp[money][num];
	if (res != -1) return res;

	res = 0;
	for (int i = 0; i <= money; i++) {
		int temp = arr[i][num] + dfs(money - i, num + 1);
		if (res < temp) {
			res = temp;
			comp[money][num] = i;
		}
	}

	return res;
}

int main() {
	int invest,outcome;
	cin >> N >> M;

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <=  N; i++) {
		cin >> invest;
		for (int j = 1; j <= M; j++) {
			cin >> outcome;
			arr[invest][j] = outcome;
		}
	}

	cout << dfs(N, 1) << endl;
	for (int i = 1; i <= M; i++) {
		cout << comp[N][i] << ' ';
		N -= comp[N][i];
	}

}