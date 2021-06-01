#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int zombie[3000001];

int main() {
	FASTIO;
	int L, range, dmg, mine;
	int mine_used = 0;
	cin >> L;
	cin >> range >> dmg;
	cin >> mine;

	for (int i = 1; i < L; i++) {
		cin >> zombie[i];
	}

	int first = range < L ? range : L;
	int later = range < L ? L : range;
	for (int i = 1; i <= first; i++) {
		int HP = zombie[i] - (dmg * (i - mine_used));
		if (HP > 0) {
			if (mine > 0) {
				mine--;
				mine_used++;
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	for (int i = first + 1; i <= later; i++) {
		int HP = zombie[i] - (dmg * (range - mine_used));
		if (HP > 0) {
			if (mine > 0) {
				mine--;
				mine_used++;
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}
	//for (int i = 0; i < L; i++) {
	//	if (zombie.front() > dmg) {
	//		if (mine_num > 0) {
	//			mine_num--;
	//			zombie[0] = 0;
	//		}
	//		else {
	//			cout << "NO";
	//			return 0;
	//		}
	//	}
	//	else
	//		for (int j = 0; j < range; j++) {
	//			if (j >= zombie.size()) break;
	//			zombie[j] -= dmg;
	//		}
	//	if (zombie.front() <= 0) zombie.erase(zombie.begin());
	//}