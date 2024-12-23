#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
#include <algorithm>
#include <windows.h>

using namespace std;

// LIS (Longest Increasing Sequence)

// Seq : 1 9 2 5 7
// �κ� ���� : �Ϻ�(0�� �̻�) ���ڸ� ����� ���� ����
// ex) 1 2 5
// ex) 1 9 5 7

// �� ���� �κ� ����
// ex) 1 2 5 O
// ex) 1 9 5 7 X

// LIS : ���� �� [�� ���� �κ� ����]�� ����
// 1 2 5 7 = ���� 4
int cache[100];
vector<int> seq;

int LIS(int pos)
{
	// ���� ����
	

	// ĳ�� Ȯ��
	int& ret = cache[pos];
	if (ret != -1)
		return ret;

	// ���ϱ�
	// seq = 1, 9, 2, 5, 7
	// 1 9 = 2
	// 1 2 5 7 = 4
	// 1 5 7 = 3
	// 1 7 = 2
	
	// �ּ� seq[pos]�� ������ 1���� ����
	ret = 1;

	// ���ϱ�
	for (int next = pos + 1; next < seq.size(); next++)
		if (seq[pos] < seq[next])
			ret = max(ret, 1 + LIS(next));

	return ret;
}

int main()
{
	::memset(cache, -1, sizeof(cache));

	seq = vector<int>{ 10, 1, 9, 2, 5, 7 };

	int ret = 0;
	for (int pos = 0; pos < seq.size(); pos++)
		ret = max(ret, LIS(pos));
}