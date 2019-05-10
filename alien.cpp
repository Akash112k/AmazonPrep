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

template <class T>
ostream &operator<<(ostream &os, stack<T> v)
{
	while (v.size() > 0)
	{
		os << (char)(v.top() + 'a') << " ";
		v.pop();
	}
	os << "\n";
	return os;
}

class Graph
{

  private:
	int _nNodes;
	int _nEdges;
	bool _isDirected;

	vector<vector<int>> _edgeList;

  protected:
	void dfsClosingTime(int c, vector<bool> &visited, stack<int> &closingTimeStack)
	{

		visited[c] = true;
		for (int v : _edgeList[c])
		{

			if (!visited[v])
				dfsClosingTime(v, visited, closingTimeStack);
		}
		closingTimeStack.push(c);
	}

	void _dfsComponentsUtil(int c, vector<bool> &visited, vector<vector<int>> &components)
	{
		components.back().push_back(c);
		visited[c] = true;
		for (int v : _edgeList[c])
		{
			if (!visited[v])
			{
				_dfsComponentsUtil(v, visited, components);
			}
		}
	}

  public:
	Graph(int n, bool isDirected = true)
	{
		_isDirected = isDirected;
		_nNodes = n;
		_edgeList.resize(n);
	}

	void addEdge(int source, int destination)
	{

		if (source >= _nNodes || destination >= _nNodes)
			throw "Invalid Input";

		_edgeList[source].push_back(destination);

		if (!_isDirected)
		{
			_nEdges++;
			_edgeList[destination].push_back(source);
		}
		_nEdges++;
	}

	vector<int> getAdjList(int vertex)
	{
		if (vertex >= _nNodes)
		{
			throw "Invalid Vertex Number";
		}
		return _edgeList[vertex];
	}

	stack<int> topologicalSort()
	{

		stack<int> closingTimeStack;
		vector<bool> visited(_nNodes, false);

		for (int i = 0; i < _nNodes; i++)
			if (!visited[i])
				dfsClosingTime(i, visited, closingTimeStack);

		return closingTimeStack;
	}

	vector<vector<int>> dfsComponents(stack<int> dfsOrder)
	{
		vector<bool> visited(_nNodes, false);
		vector<vector<int>> components;
		while (dfsOrder.size() > 0)
		{
			int top = dfsOrder.top();
			dfsOrder.pop();
			if (!visited[top])
			{
				components.push_back(vector<int>());
				_dfsComponentsUtil(top, visited, components);
			}
		}
		return components;
	}

	Graph transpose()
	{
		Graph transposeGraph(_nNodes, _isDirected);

		for (int i = 0; i < _nNodes; i++)
			for (int v : _edgeList[i])
				transposeGraph.addEdge(v, i);
		return transposeGraph;
	}

	vector<vector<int>> stronglyConnectedComponents()
	{
		stack<int> closingTimeStack = topologicalSort();
		Graph transposeGraph = this->transpose();
		return transposeGraph.dfsComponents(closingTimeStack);
	}
};

main()
{

	string arr[5] = {"baa", "abcd", "abca", "cab", "cad"};

	set<char> charCount;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < arr[i].length(); j++)
			charCount.insert(arr[i][j]);

	Graph g(charCount.size());

	for (int i = 0; i < 4; i++)
	{

		string w1 = arr[i];
		string w2 = arr[i + 1];
		for (int j = 0; j < w1.length() && j < w2.length(); j++)
		{
			if (w1[j] != w2[j])
			{
				g.addEdge(w1[j] - 'a', w2[j] - 'a');
				break;
			}
		}
	}
	cout << g.topologicalSort() << endl;
}