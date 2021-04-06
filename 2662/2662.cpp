#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int arr[303][22], dp[303][22], comp[303][22];
// arr[i][j] : i�� ���� jȸ�翡 �־��� ���� ����
// dp[i][j] : i�� ���� ������ j��° ȸ�翡 ������ �� �ִ� ���ͱ�
// comp[i][j] : i�� ������ j��° ȸ�翡 �������� ���� ���ڱ�

int dfs(int money, int num) {
	if (num > M) return 0; // ��� ȸ�� Ž���ϸ� ����
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