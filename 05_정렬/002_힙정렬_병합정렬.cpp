#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
#include <algorithm>

using namespace std;

// �����İ� ��������

// �� ���� O(NlogN)
void HeapSort(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>> pq;

	
	for (int num : v)
		pq.push(num);

	v.clear();

	
	while (pq.empty() == false)
	{
		v.push_back(pq.top());
		pq.pop();
	}
}

// ���� ���� O(NlogN)

// ���� ���� (Divide and Conquer)
// - ���� (Divide)		������ �� �ܼ��ϰ� ����
// - ���� (Conquer)		���ҵ� ������ �ذ�
// - ���� (Combine)		����� �����Ͽ� ������

// [3][K][7][2][J][4][8][9]				8�� * 1
// -> [3][K][7][2]/[J][4][8][9]			4�� * 2
// -> [3][K]/[7][2]/[J][4]/[8][9]		2�� * 4
// -> [3]/[K]/[7]/[2]/[J]/[4]/[8]/[9]	1�� * 8
// -> [3][K]/[2][7]/[4][J]/[8][9]		2�� * 4

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	// [2][3][7][K][4][8][9][J]
	// [l]         [r]
	int leftidx = left;
	int rightidx = mid + 1;
	vector<int> temp;

	while (leftidx <= mid && rightidx <= right)
	{
		if (v[leftidx] <= v[rightidx])
		{
			temp.push_back(v[leftidx]);
			leftidx++;
		}
		else
		{
			temp.push_back(v[rightidx]);
			rightidx++;
		}
	}

	// ������ ���� ��������, ������ ������ ������ ����
	if (leftidx > mid)
	{
		while (rightidx <= right)
		{
			temp.push_back(v[rightidx]);
			rightidx++;
		}
	}
	// �������� ���� ��������, ���� ������ ������ ����
	else
	{
		while (leftidx <= mid)
		{
			temp.push_back(v[leftidx]);
			leftidx++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
		v[left + i] = temp[i];
}

void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	MergeSort(v, left, mid); // 4
	MergeSort(v, mid + 1, right); // 4

	MergeResult(v, left, mid, right);
}



int main()
{
	vector<int>v;

	srand(time(0));

	for (int i = 0; i < 50; i++)
	{
		int randValue = rand() % 100;
		v.push_back(randValue);
	}

	MergeSort(v, 0, v.size() - 1);
}