#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

int ccw(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3)
{
	ll temp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;

	temp = temp - p1.second * p2.first - p2.second * p3.first - p3.second * p1.first;

	if (temp > 0) return 1; // 반시계
	else if (temp == 0) return 0;
	else if (temp < 0) return -1; // 시계
}

bool chk(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d) {
	int abc = ccw(a, b, c);
	int abd = ccw(a, b, d);
	int cda = ccw(c, d, a);
	int cdb = ccw(c, d, b);
	if (abc * abd == 0 && cda * cdb == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);

		return a <= d && c <= b;
	}
	return abc * abd <= 0 && cda * cdb <= 0;
}

int main() {
	FASTIO;
	int x1, x2, x3, y1, y2, y3, x4, y4;
	pair<ll, ll> a, b, c, d;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	a = make_pair(x1, y1);
	b = make_pair(x2, y2);
	c = make_pair(x3, y3);
	d = make_pair(x4, y4);

	if (chk(a, b, c, d)) cout << 1;
	else cout << 0;
}