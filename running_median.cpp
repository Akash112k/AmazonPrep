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

template <typename T, typename Comparator = std::less<T>>
class Heap
{
private:
	int _size;
	vector<T> arr;

	Comparator _comp;

protected:
	void heapify(int pos)
	{

		int lc = pos * 2 + 1;
		int rc = pos * 2 + 2;
		int correctElement = pos;
		if (lc < _size && _comp(arr[correctElement], arr[lc]))
		{
			correctElement = lc;
		}
		if (rc < _size && _comp(arr[correctElement], arr[rc]))
		{
			correctElement = rc;
		}

		if (correctElement != pos)
		{

			T temp = arr[pos];
			arr[pos] = arr[correctElement];
			arr[correctElement] = temp;
			heapify(correctElement);
		}
	}

	void updatePosition(int index)
	{

		while (index > 0 && _comp(arr[(index - 1) / 2], arr[index]))
		{

			T temp = arr[index];
			arr[index] = arr[(index - 1) / 2];
			arr[(index - 1) / 2] = temp;

			index = (index - 1) / 2;
		}
	}

public:
	Heap(Comparator _c = Comparator()) : _comp(_c)
	{
		_size = 0;
	}

	int size()
	{
		return _size;
	}

	T top()
	{
		if (_size == 0)
		{
			throw "Underflow";
		}
		return arr[0];
	}

	T extractTop()
	{
		if (_size == 0)
		{
			throw "Underflow";
		}
		T val = arr[0];
		arr[0] = arr[_size - 1];
		_size--;
		arr.pop_back();
		heapify(0);
		return val;
	}

	void insert(T val)
	{
		arr.push_back(val);
		_size++;
		updatePosition(_size - 1);
	}

	void clear()
	{
		_size = 0;
		arr.clear();
	}
};

main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	Heap<int, greater<double>> a;
	try
	{
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			a.insert(x);
			cout << "Current Top is " << a.top() << endl;
		}
		while (a.size() > 0)
		{
			int z = a.extractTop();
			cout << "Extracted " << z << endl;
		}
	}
	catch (exception &exc)
	{
		cout << exc.what();
	}
}