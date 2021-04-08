#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(string a, string b) { //문자열 비교, 앞 자리 수가 작은 수 부터 정렬
	return a + b < b + a;
}

int main() {
	int k, n, i;
	int maxlen = 0;
	string str;
	vector<string> num_arr;
	cin >> k >> n;

	for (i = 0; i < k; i++) {
		cin >> str;
		if (str.length() > maxlen)
			maxlen = str.length();
		num_arr.push_back(str);
	}
	sort(num_arr.begin(), num_arr.end(),cmp);

	for (i = k - 1; i >= 0; i--) {
		if (num_arr[i].length() == maxlen) {
			for (int j = 0; j <= n - k; j++)
				cout << num_arr[i];
			i--;
			break;
		}
		cout << num_arr[i];
	}

	for (i; i >= 0; i--) {
		cout << num_arr[i];
	}
}
