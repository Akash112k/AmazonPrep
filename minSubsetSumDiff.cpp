/*

Given a set of integers, the task is to divide it into two sets 
	S1 and S2 such that the absolute difference between their sums is minimum.

If there is a set S with n elements, then if we assume Subset1 has m elements, 
	Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) 
	should be minimum.

*/

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

int findMin(int arr[], int n)
{
	vector<int> dp(n, INT_MAX);
	int totalSum = 0;
	for (int i = 0; i < n; i++)
		totalSum += arr[i];
	int totalSumHalf = totalSum / 2;
	for(int i=0;i<n;i++)
		dp[i] = min(totalSumHalf - arr[i],totalSumHalf);
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
		{
			int valj = totalSumHalf - dp[j];
			int diff = totalSumHalf - (valj + arr[i]);
			if(abs(diff)<abs(dp[i]))
				dp[i] = diff;
		}
	int nearIndex = 0;
	for(int i=0;i<n;i++)
		if( abs(dp[i]) < abs(dp[nearIndex]) )
			nearIndex = i;
	return (totalSum-(totalSumHalf - dp[nearIndex])) - (totalSumHalf - dp[nearIndex]);
}

main()
{
	int arr[] = {1,7	,11,5};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The minimum difference between 2 sets is "
		 << findMin(arr, n)<<endl;
	return 0;
}