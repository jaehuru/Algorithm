#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
#include <algorithm>

using namespace std;

// ������ ���� : ����

// -> A* OpenList (PQ)
// -> C# List = C++ vector

// PQ(�켱���� ť) O(logN)
// Red-Black Tree O(logN)
// Sorting ? 

// ��Ŀ�� ĥ�� ī����� �ް� �����Ҷ��� �����غ���.

// 1) ���� ���� (Bubble Sort) 0(N^2)
void BubbleSort(vector<int>& v)
{
	const int n = v.size();

	// (N-1) + (N-2) + ... + 2 + 1
	// ���������� �� = N * (N-1) / 2
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < (n - 1 - i); j++)
		{
			if (v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

// 2) ���� ���� (Selection Sort) 0(N^2)
void SelectionSort(vector<int>& v)
{
	const int n = v.size();

	for (int i = 0; i < n - 1; i++)
	{
		int Min = i;

		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[Min])
				Min = j;
		}

		// ��ȯ
		int temp = v[i];
		v[i] = v[Min];
		v[Min] = temp;
	}
}

// 3) ���� ���� (Insertion Sort) 0(N^2)
void InsertionSort(vector<int>& v)
{
	const int n = v.size();

	
	for (int i = 1; i < n; i++)
	{
		int insertData = v[i];

		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (v[j] > insertData)
				v[j + 1] = v[j];
			else
				break;
		}

		v[j + 1] = insertData;
	}
}

int main()
{
	vector<int> v{ 5, 3, 1, 4, 2 };

	InsertionSort(v);
}