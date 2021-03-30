#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int k , n;
	string num;
	vector<string> num_arr;
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		cin >> num;
		num_arr.push_back(num)  ;
	}
	sort(num_arr.begin(), num_arr.end());

	for (int i = 0; i < k; i++) {
		cout << num_arr[i];
	}
}