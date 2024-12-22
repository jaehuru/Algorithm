#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
#include <algorithm>

using namespace std;

// �׷���/Ʈ�� ����
// �ּ� ���д� Ʈ�� (Minimum Spanning Tree) / �ּ� ���� Ʈ��

// ��ȣ ��Ÿ�� ���� (Disjoint Set)
// -> ���Ͽ�-���ε� Union-Find (��ġ��-ã��)

// Lineage Battleground (ȥ��!)
// ������ + �����̹�
// 1�� �� 1000�� (��ID 0~999)
// ���� (1���� + 2���� = 1����)

void LineageBattleground()
{
	struct User
	{
		int teamID;
		// TODO
	};

	// TODO : UserManager
	vector<User> users;
	for (int i = 0; i < 1000; i++)
	{
		users.push_back(User{ i });
	}

	// �� ����
	// user[1] <-> users[5]
	users[5].teamID = users[1].teamID; // 1

	// [0][1][2][3][4]...[999]
	// [1][1][1][1][1]...[2][2][2][2]...[999]

	// teamID=1�� ���� teamID=2�� ���� ����
	for (User& user : users)
	{
		if (user.teamID == 1)
			user.teamID = 2;
	}

	// ã�� ���� O(1)
	// ��ġ�� ���� O(N)
}

// Ʈ�� ������ �̿��� ��ȣ ��Ÿ�� ������ ǥ��
// [0] [1] [2] [3] [4] [5]
struct Node
{
	Node* leader;
};

// [1]       [3]
// [2]	  [4][5][1]
//           [0][2]

// �ð� ���⵵ : Ʈ���� ���̿� ����� �ð��� �ɸ�
class NaiveDisjointSet
{
public:
	NaiveDisjointSet(int n) :
		_parent(n)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	// �� ������ ������?
	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		return Find(_parent[u]);
	}

	// u�� v�� ��ģ�� (�ϴ� u�� v ������)
	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		_parent[u] = v;
	}

private:
	vector<int> _parent;
};

// Ʈ���� �������� ���� ������ �ذ�?
// Ʈ���� ��ĥ��, �׻� [���̰� ���� Ʈ����] [���̰� ���� Ʈ��] ������
// (Union-By-Rank) ��ũ�� ���� ��ġ�� ����ȭ

// �ð����⵵ O(Ackermann(n)) = O(1)
class DisjointSet
{
public:
	DisjointSet(int n) : _parent(n), _rank(n, 1)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	// ���� ���¹� ����?
	// [1]		[3]
	// [2]	 [4][5][0]
	// 		    

	// �� ������ ������?
	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		//_parent[u] = Find(_parent[u]);
		//return _parent[u];

		return _parent[u] = Find(_parent[u]);
	}

	// u�� v�� ��ģ��
	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		if (_rank[u] > _rank[v])
			swap(u, v);

		// rank[u] <= rank[v] �����
		_parent[u] = v;

		if (_rank[u] == _rank[v])
			_rank[v]++;
	}

private:
	vector<int> _parent;
	vector<int> _rank;
};


int main()
{
	DisjointSet teams(1000);

	teams.Merge(10, 1);
	int teamId = teams.Find(1);
	int teamId2 = teams.Find(10);

	teams.Merge(3, 2);
	int teamId3 = teams.Find(3);
	int teamId4 = teams.Find(2); 

	teams.Merge(1, 3);
	int teamId6 = teams.Find(1);
	int teamId7 = teams.Find(3);
}