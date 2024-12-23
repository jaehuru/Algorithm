#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
#include <algorithm>
#include <windows.h>

using namespace std;

// ENCHANT

// +0 �����
// ���� ��ȭ �ֹ��� -> +1 / +2 / +3 �� �ϳ�

// +N ����� �ߴ� ����� ����?
// ex) +1 +2 +3 +4 ... +9
// ex) +3 +6 +9
// ex) +1 +3 +4

int N;
int cache[100];

// [+num]���� �����ؼ�, [+N]���� ���� ����� ��
int Enchant(int num)
{
	// ���� ���
	if (num > N)
		return 0;
	if (num == N)
		return 1;

	// ĳ��
	int& ret = cache[num];
	if (ret != -1)
		return ret;

	// ����
	return ret = Enchant(num + 1) + Enchant(num + 2) + Enchant(num + 3);
}

int main()
{
	N = 9;

	memset(cache, -1, sizeof(cache));

	int ret = Enchant(0);
	cout << ret << endl;
}