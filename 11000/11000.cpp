/*
모든 회의를 진행시키기 위한 최소 회의실 수 구하기 
그리디 알고리즘 사용
회의 시작시간이 빠른 순으로 정렬 후 (같을 경우엔 종료시간이 빠른 순) 최소 큐에 첫 회의 종료시간 삽입.
이후 회의의 시작 시간이 최소 큐의 top값 보다 작으면 최소 큐에 push, 크거나 같으면 top 제거 후 push.
큐의 개수가 회의실 사용 수
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct meeting {
	int start;
	int end;
};

void merge(meeting* initArr, meeting* mergedArr, int l, int m, int n) {//initArr[l:m], initArr[m+1:n]을 정렬해 mergedArr[l:n]에 저장.
	int i1, iResult, i2;
	i1 = iResult = l;
	i2 = m + 1;

	while (i1 <= m && i2 <= n) { //두 배열 비교해 작은 값 부터 순서대로 저장.
		if (initArr[i1].start == initArr[i2].start) {
			if (initArr[i1].end < initArr[i2].end) mergedArr[iResult++] = initArr[i1++];
			else mergedArr[iResult++] = initArr[i2++];
		}
		else if (initArr[i1].start < initArr[i2].start) mergedArr[iResult++] = initArr[i1++];
		else mergedArr[iResult++] = initArr[i2++];
	}

	copy(initArr + i1, initArr + m + 1, mergedArr + iResult); //m과 n의 길이가 다를 경우 한 쪽이 먼저 끝남. 나머지 값 삽입.
	copy(initArr + i2, initArr + n + 1, mergedArr + iResult);
}

void recursiveMerge(meeting* arr, meeting* tempArr, int left, int right) {//arr[left:right] 재귀합병정렬
	if (left >= right) return;
	int mid = (left + right) / 2; // 배열의 절반
	recursiveMerge(arr, tempArr, left, mid);
	recursiveMerge(arr, tempArr, mid + 1, right); //각 절반을 매개변수로 재귀적 호출 -> 절반씩 쪼개짐
	merge(arr, tempArr, left, mid, right); //다 쪼개질 경우 merge로 합쳐서 tempArr에 저장
	copy(tempArr + left, tempArr + right + 1, arr + left);// 정리된 배열 arr에 다시 넣음. 다음 합병을 위함.
}

void rmergeSort(meeting* arr, int n) {
	meeting* tempArr = new meeting[n + 1];
	recursiveMerge(arr, tempArr, 0, n);
	copy(tempArr, tempArr + n, arr);
}

int main() {
	int num, start, end;
	priority_queue<int,vector<int>,greater<int>> room; //최소 큐

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