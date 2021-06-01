#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
using namespace std;


ll power(ll x, ll y, ll z) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % z;
		}
		x = x * x % z;
		y /= 2;
	}
	return ret;
}
int main() {

}