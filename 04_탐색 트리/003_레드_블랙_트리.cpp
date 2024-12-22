#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
#include "RedBlackTree.h"
#include <thread>

// 레드 블랙 트리

//   [20]
// [10]   [30]
//      [25]  [40]
//				 [50]
int main()
{
	RedBlackTree rbt;

	rbt.Insert(30);
	rbt.Print();
	this_thread::sleep_for(1s);

	rbt.Insert(10);
	rbt.Print();
	this_thread::sleep_for(1s);

	rbt.Insert(20);
	rbt.Print();
	this_thread::sleep_for(1s);

	rbt.Insert(25);
	rbt.Print();
	this_thread::sleep_for(1s);

	rbt.Delete(20);
	rbt.Print();
	this_thread::sleep_for(1s);

	rbt.Delete(10);
	rbt.Print();
	this_thread::sleep_for(1s);
}