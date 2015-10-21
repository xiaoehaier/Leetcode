#include <iostream>
using std::cout;
using std::cin;
using std::endl;

struct ListNode
{
	int value;
	ListNode *next;
	ListNode(int val):value(val), next(NULL){}
};

int fibonacci(int n)
{
	if (n == 1) return 0;
	if (n == 2) return 1;

	ListNode a(0);
	ListNode b(1);
	a.next = &b;
	b.next = &a;
	ListNode *cur = &b;
	n -= 2;

	while(n--) {
		cur->next->value += cur->value;
		cur = cur->next;
	}

	return cur->value;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	cout << fibonacci(n) << endl;

	return 0;
}
