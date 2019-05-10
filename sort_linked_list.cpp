#include <bits/stdc++.h>
#define pb push_back
#define ll long long int
#define pi pair<int, int>
#define endl "\n"
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);
#define TESTS      \
	int TCASES;    \
	cin >> TCASES; \
	while (TCASES--)
#define all(v) v.begin(), v.end()
#define mkp make_pair
#define asort(v) sort(all(v));
#define rsort(v) \
	asort(v);    \
	reverse(all(v));
#define MOD 1000000007
using namespace std;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
	for (int it = 0; it < v.size(); it++)
	{
		os << v[it] << " ";
	}
	os << "\n";
	return os;
}

struct node
{
	int data;
	struct node *next;

	node(int d)
	{
		data = d;
		next = NULL;
	}
};

size_t length(node *head)
{
	size_t x = 0;
	while (head != NULL)
	{
		x++;
		head = head->next;
	}
	return x;
}

void display(node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n\n";
}

node *sortLinkedList(node *head, int sz)
{
	if (sz == 1)
		return head;
	int mid = sz / 2;
	node *firstHalf = head;
	node *secondHalf = NULL;

	int ce = 1;
	while (ce != mid)
	{
		head = head->next;
		ce++;
	}
	secondHalf = head->next;

	head->next = NULL;

	firstHalf = sortLinkedList(firstHalf, mid);
	secondHalf = sortLinkedList(secondHalf, sz - mid);

	node *sortedHead = NULL;
	node *sortedTail = NULL;

	while (firstHalf != NULL && secondHalf != NULL)
	{
		if (firstHalf->data < secondHalf->data)
		{
			if (sortedHead == NULL)
			{
				sortedHead = sortedTail = firstHalf;
				firstHalf = firstHalf->next;
				sortedHead->next = NULL;
			}
			else
			{
				sortedTail->next = firstHalf;
				sortedTail = sortedTail->next;
				firstHalf = firstHalf->next;
				sortedTail->next = NULL;
			}
		}
		else
		{
			if (sortedHead == NULL)
			{
				sortedHead = sortedTail = secondHalf;
				secondHalf = secondHalf->next;
				sortedHead->next = NULL;
			}
			else
			{
				sortedTail->next = secondHalf;
				sortedTail = sortedTail->next;
				secondHalf = secondHalf->next;
				sortedTail->next = NULL;
			}
		}
	}

	while (firstHalf != NULL)
	{
		if (sortedHead == NULL)
		{
			sortedHead = sortedTail = firstHalf;
			firstHalf = firstHalf->next;
			sortedHead->next = NULL;
		}
		else
		{
			sortedTail->next = firstHalf;
			sortedTail = sortedTail->next;
			firstHalf = firstHalf->next;
			sortedTail->next = NULL;
		}
	}

	while (secondHalf != NULL)
	{
		if (sortedHead == NULL)
		{
			sortedHead = sortedTail = secondHalf;
			secondHalf = secondHalf->next;
			sortedHead->next = NULL;
		}
		else
		{
			sortedTail->next = secondHalf;
			sortedTail = sortedTail->next;
			secondHalf = secondHalf->next;
			sortedTail->next = NULL;
		}
	}
	return sortedHead;
}

main()
{
	struct node *head = NULL;
	cout << "Enter the number of elements";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{

		int x;
		cin >> x;
		if (head == NULL)
			head = new node(x);
		else
		{
			node *temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new node(x);
		}
	}
	size_t sz = length(head);
	cout << "Before sorting ";
	display(head);
	struct node *sortedHead = sortLinkedList(head, sz);
	cout << "After Sorting ";
	display(sortedHead);
}