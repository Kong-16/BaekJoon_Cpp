#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

#define MAXSIZE 105
typedef pair<int, int> pii;

int maze[MAXSIZE][MAXSIZE] = { 0, };
int visited[MAXSIZE][MAXSIZE] = { 0, };
int result[MAXSIZE][MAXSIZE];

pii dir[4] = { {1,0}, {0,-1}, {-1,0}, {0,1} };

void bfs() {
	queue<pii> q;
	q.push(pii(1, 1));
	result[1][1] = 1;
	visited[1][1] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x_dir = x + dir[i].first;
			int y_dir = y + dir[i].second;
			if (maze[x_dir][y_dir] == 1 && visited[x_dir][y_dir] == 0) {
				q.push(pii(x_dir, y_dir));
				visited[x_dir][y_dir] = visited[x][y] + 1;
			}
		}
	}
}

int main() {
	int N, M;
	string str;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= M; j++) maze[i][j] = str[j - 1] - '0';
	}
	bfs();
	cout << visited[N][M];

}