#include <iostream>
#include <fstream>

using namespace std;

struct meeting {
	int start;
	int end;
};

void meeting_sort(meeting* meeting_arr, int start, int end) { // quick sort ������� end �� ���� ������ ����
	if (left < right) {
		int left = start;
		int right = end +1;
		int pivot = meeting_arr[left].end;
		do {
			do left++; while (meeting_arr[left].end < pivot);
			do right--; while (meeting_arr[right].end > pivot);
			if (left < right) swap(meeting_arr[left], meeting_arr[right]);
		} while (left < right);
		swap(meeting_arr[start], meeting_arr[right]);

		meeting_sort(meeting_arr, start, right - 1);
		meeting_sort(meeting_arr, right + 1, end);
	}
}

void quickSort(meeting* arr, int left, int right) { //arr[left:right] ������
	if (left < right) { // right�� left���� ������ ����.
		int pivot = arr[left].end;
		int i = left + 1; int j = right;
		while (i < j) { // i�� j�� �������� ����.
			while (arr[i].end <= pivot && i < right + 1) i++;
			while (arr[j].end > pivot && j > left) j--;
			if (i < j) swap(arr[i], arr[j]);
		} // while����� arr[j]�� ���� �����ʿ� ��ġ�� pivot���� ���� ��. 
		swap(arr[left], arr[j]);//���� arr[j]�� pivot�� ��ġ�� arr[left] �ٲ��ָ� arr[left]�� ���ڸ��� ��.
		quickSort(arr, left, j - 1);
		quickSort(arr, j + 1, right);
	}
}

int main() {
	int num ,start, end, count;
	fstream fin("test.txt");
	
	count = 1;
	fin >> num;

	meeting* meeting_arr = new meeting[num];
	for (int i = 0; i < num; i++) {
		fin >> start >> end;
		meeting_arr[i].start = start;
		meeting_arr[i].end = end;
	}


	for (int i = 0; i < num; i++) {
		cout <<meeting_arr[i].start<< meeting_arr[i].end<<endl;
	}
	cout << endl;

	quickSort(meeting_arr, 0, num - 1);

	for (int i = 0; i < num; i++) {
		cout << meeting_arr[i].start << meeting_arr[i].end << endl;
	}
	cout << endl;

	end = meeting_arr[0].end;

	for (int i = 1; i < num; i++) {
		if (meeting_arr[i].end < end) {
			count++;
			end = meeting_arr[i].end;
		}
	}
	cout << count;
}