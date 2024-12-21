#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
#include <algorithm>

using namespace std;

// 오늘의 주제 : 정렬

// -> A* OpenList (PQ)
// -> C# List = C++ vector

// PQ(우선순위 큐) O(logN)
// Red-Black Tree O(logN)
// Sorting ? 

// 포커를 칠때 카드들을 받고 정리할때를 생각해보기.

// 1) 버블 정렬 (Bubble Sort) 0(N^2)
void BubbleSort(vector<int>& v)
{
	const int n = v.size();

	// (N-1) + (N-2) + ... + 2 + 1
	// 등차수열의 합 = N * (N-1) / 2
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

// 2) 선택 정렬 (Selection Sort) 0(N^2)
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

		// 교환
		int temp = v[i];
		v[i] = v[Min];
		v[Min] = temp;
	}
}

// 3) 삽입 정렬 (Insertion Sort) 0(N^2)
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