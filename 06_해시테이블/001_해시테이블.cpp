#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
#include <algorithm>

using namespace std;

// 오늘의 주제 : 해시테이블

// Q) map vs hash_map (C++ 표준 unordered_map)

// map : Red-Black Tree
// - 추카/탐색/삭제 O(logN)

// C# dictionary = C++ map (X)
// C# dictionary = C++ unordered_map (O)

// hash_map (unordered_map)
// -추카/탐색/삭제 O(1)

// 살은 내주고 뼈를 취한다!
// 메모리를 내주고 속도를 취한다!

// 아파트 우편함
// [201][202][203][204][205]
// [101][102][103][104][105]

// 1~999(key값)
// [1][2][3][][][][999]

// '해시' '테이블'
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

	// 777번 유저 정보 세팅
	users[777] = User{ 777, "jaehuru" };

	// 777번 유저 이름은?
	string name = users[777].username;
	cout << name << endl;

	// 테이블
	// 키를 알면, 데이터를 단번에 찾을 수 있다!

	// 문제의 상황
	// int32_max (3억~)
	// 살을 내주는것도 정도껏 내줘야함
	// 메모리도 무한은 아니다!
}

// 보안
// ID: jaehuru + PW : qwer1234
// ID: jaehuru + PW : hash(qwer1234) -> sdaf123!2@#sdasdj2321

// DB [jaehuru][sdaf123!2@#sdasdj2321]
// 비밀번호 찾기 -> 아이디 입력 / 폰 인증 -> 새 비밀번호를 입력하세요.


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
	int key = (userID % 1000); // hash < 고유번호

	// 123456789번 유저 정보 세팅
	users[key] = User{ userID, "jaehuru" };

	// 123456789번 유저 이름은?
	User& user = users[key];
	if (user.userID == userID)
	{
		string name = user.username;
		cout << name << endl;
	}

	// 충돌 문제
	// 동일한 값이 나오게 된다면

	// 충돌한 발생한 자리를 대신해서 다른 빈자리를 찾아나서면 된다
	// - 선형 조사법 (linear probing)
	// hash(key) + 1 -> hash(key) + 2
	// - 이차 조사법 (quadratic probing)
	// hash(key) + 1^2 -> hash(key) + 2^2
	// - etc

	// 체이닝
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
	int key = (userID % 1000); // hash < 고유번호

	// 123456789번 유저 정보 세팅
	users[key].push_back(User{ userID, "jaehuru" });
	users[789].push_back(User{ 789, "haker" });

	// 123456789번 유저 이름은?
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