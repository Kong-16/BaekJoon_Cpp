#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int cross(int x1, int y1, int x2, int y2) {
	return x1 * y2 - x2 * y1;
}

int main() {
	FASTIO;
	int x1, x2, x3, y1, y2, y3, vecx1, vecy1, vecx2, vecy2, res;
	
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	vecx1 = x2 - x1;
	vecy1 = y2 - y1;
	vecx2 = x3 - x1;
	vecy2 = y3 - y1;

	res = cross(vecx1, vecy1, vecx2, vecy2);
	if (res > 0) cout << 1;
	else if (res < 0) cout << -1;
	else cout << 0;

}