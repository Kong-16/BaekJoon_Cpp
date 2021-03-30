/*
��� ȸ�Ǹ� �����Ű�� ���� �ּ� ȸ�ǽ� �� ���ϱ� 
�׸��� �˰��� ���
ȸ�� ���۽ð��� ���� ������ ���� �� (���� ��쿣 ����ð��� ���� ��) �ּ� ť�� ù ȸ�� ����ð� ����.
���� ȸ���� ���� �ð��� �ּ� ť�� top�� ���� ������ �ּ� ť�� push, ũ�ų� ������ top ���� �� push.
ť�� ������ ȸ�ǽ� ��� ��
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct meeting {
	int start;
	int end;
};

void merge(meeting* initArr, meeting* mergedArr, int l, int m, int n) {//initArr[l:m], initArr[m+1:n]�� ������ mergedArr[l:n]�� ����.
	int i1, iResult, i2;
	i1 = iResult = l;
	i2 = m + 1;

	while (i1 <= m && i2 <= n) { //�� �迭 ���� ���� �� ���� ������� ����.
		if (initArr[i1].start == initArr[i2].start) {
			if (initArr[i1].end < initArr[i2].end) mergedArr[iResult++] = initArr[i1++];
			else mergedArr[iResult++] = initArr[i2++];
		}
		else if (initArr[i1].start < initArr[i2].start) mergedArr[iResult++] = initArr[i1++];
		else mergedArr[iResult++] = initArr[i2++];
	}

	copy(initArr + i1, initArr + m + 1, mergedArr + iResult); //m�� n�� ���̰� �ٸ� ��� �� ���� ���� ����. ������ �� ����.
	copy(initArr + i2, initArr + n + 1, mergedArr + iResult);
}

void recursiveMerge(meeting* arr, meeting* tempArr, int left, int right) {//arr[left:right] ����պ�����
	if (left >= right) return;
	int mid = (left + right) / 2; // �迭�� ����
	recursiveMerge(arr, tempArr, left, mid);
	recursiveMerge(arr, tempArr, mid + 1, right); //�� ������ �Ű������� ����� ȣ�� -> ���ݾ� �ɰ���
	merge(arr, tempArr, left, mid, right); //�� �ɰ��� ��� merge�� ���ļ� tempArr�� ����
	copy(tempArr + left, tempArr + right + 1, arr + left);// ������ �迭 arr�� �ٽ� ����. ���� �պ��� ����.
}

void rmergeSort(meeting* arr, int n) {
	meeting* tempArr = new meeting[n + 1];
	recursiveMerge(arr, tempArr, 0, n);
	copy(tempArr, tempArr + n, arr);
}

int main() {
	int num, start, end;
	priority_queue<int,vector<int>,greater<int>> room; //�ּ� ť

	cin >> num;

	meeting* meeting_arr = new meeting[num];

	for (int i = 0; i < num; i++) {
		cin >> start >> end;
		meeting_arr[i].start = start;
		meeting_arr[i].end = end;
	}

	rmergeSort(meeting_arr, num - 1);

	room.push(meeting_arr[0].end);
	for (int i = 1; i < num; i++) {
		if (meeting_arr[i].start >= room.top())
			room.pop();
		room.push(meeting_arr[i].end);
	}

	cout << room.size();
}