#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
#include <algorithm>

using namespace std;

// ������ ���� : �ؽ����̺�

// Q) map vs hash_map (C++ ǥ�� unordered_map)

// map : Red-Black Tree
// - ��ī/Ž��/���� O(logN)

// C# dictionary = C++ map (X)
// C# dictionary = C++ unordered_map (O)

// hash_map (unordered_map)
// -��ī/Ž��/���� O(1)

// ���� ���ְ� ���� ���Ѵ�!
// �޸𸮸� ���ְ� �ӵ��� ���Ѵ�!

// ����Ʈ ������
// [201][202][203][204][205]
// [101][102][103][104][105]

// 1~999(key��)
// [1][2][3][][][][999]

// '�ؽ�' '���̺�'
// O(1)
void TestTable()
{
	struct User
	{
		int userID = 0; // 1~999
		string username;
	};

	vector<User> users;
	users.resize(1000);

	// 777�� ���� ���� ����
	users[777] = User{ 777, "jaehuru" };

	// 777�� ���� �̸���?
	string name = users[777].username;
	cout << name << endl;

	// ���̺�
	// Ű�� �˸�, �����͸� �ܹ��� ã�� �� �ִ�!

	// ������ ��Ȳ
	// int32_max (3��~)
	// ���� ���ִ°͵� ������ �������
	// �޸𸮵� ������ �ƴϴ�!
}

// ����
// ID: jaehuru + PW : qwer1234
// ID: jaehuru + PW : hash(qwer1234) -> sdaf123!2@#sdasdj2321

// DB [jaehuru][sdaf123!2@#sdasdj2321]
// ��й�ȣ ã�� -> ���̵� �Է� / �� ���� -> �� ��й�ȣ�� �Է��ϼ���.


void TestHash()
{
	struct User
	{
		int userID = 0; // 1~int32_max
		string username;
	};

	//       []
	// [][][][][][][][]
	vector<User> users;
	users.resize(1000);

	const int userID = 123456789;
	int key = (userID % 1000); // hash < ������ȣ

	// 123456789�� ���� ���� ����
	users[key] = User{ userID, "jaehuru" };

	// 123456789�� ���� �̸���?
	User& user = users[key];
	if (user.userID == userID)
	{
		string name = user.username;
		cout << name << endl;
	}

	// �浹 ����
	// ������ ���� ������ �ȴٸ�

	// �浹�� �߻��� �ڸ��� ����ؼ� �ٸ� ���ڸ��� ã�Ƴ����� �ȴ�
	// - ���� ����� (linear probing)
	// hash(key) + 1 -> hash(key) + 2
	// - ���� ����� (quadratic probing)
	// hash(key) + 1^2 -> hash(key) + 2^2
	// - etc

	// ü�̴�
}

// 0(1)
void TestHashTableChaining()
{
	struct User
	{
		int userID = 0; // 1~int32_max
		string username;
	};

	// [ ][ ][ ][ ][ ][ ][ ][ ][ ]
	vector<vector<User>> users;
	users.resize(1000);

	const int userID = 123456789;
	int key = (userID % 1000); // hash < ������ȣ

	// 123456789�� ���� ���� ����
	users[key].push_back(User{ userID, "jaehuru" });
	users[789].push_back(User{ 789, "haker" });

	// 123456789�� ���� �̸���?
	vector<User>& bucket = users[key];
	for (User& user : bucket)
	{
		if (user.userID == userID)
		{
			string name = user.username;
			cout << name << endl;
		}
	}
}

int main()
{
	TestHashTableChaining();
}