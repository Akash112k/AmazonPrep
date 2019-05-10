#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
#define pi pair<int,int>
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TESTS int TCASES;cin>>TCASES;while(TCASES--)
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define asort(v) sort(all(v));
#define rsort(v) asort(v);reverse(all(v));
#define MOD 1000000007
using namespace std;
template<class T>
ostream& operator<<(ostream& os,const vector<T> &v)
{
	for(int it=0;it<v.size();it++)
	{
		os<<v[it]<<" ";
	}
	os<<"\n";
	return os;
}

// Longest subsequence of integers such that all numbers has atleast a digit common with it's adjacent number


bool hasCommon(int a,int b){
	while(a)
	{
		int z = b;
		int t = a%10;
		while(z)
		{
			if(z%10==t){
				return true;
			}
			z/=10;
		}
		a/=10;
	}
	return false;
}

int solve(int arr[],int n)
{
	int dp[n];
	for(int i=0;i<n;i++)
	{
		d[i] = 1;
	}
	cout<<endl;
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(hasCommon(arr[i],arr[j]))
				dp[i] = max(dp[i],dp[j]+1);
	for(int i=0;i<n;i++)
	{
		cout<<dp[i]<<" ";
	}
}

main()
{
	int arr[] = {11,22,33,44,54,56,63};
	int n=7;
	solve(arr,n);
	cout<<endl;
}