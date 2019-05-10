#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
#define pi pair<int,int>
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TESTS int TCASES;cin>>TCASES;while(TCASES--)
#define debug_log(v) cout<<"Debug Print -- "<<#v<<" is "<<v<<"\n";
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

void rotate(vector<vector<int>> &arr)
{
	int n = arr.size();
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n-i-1;j++)
		{
			int temp = arr[i][j];
			swap(arr[n-j-1][i],temp);
			swap(arr[n-i-1][n-j-1],temp);
			swap(arr[j][n-i-1],temp);
			swap(arr[i][j],temp);
		}
	}
}


main()
{
	int n=10;
	vector<vector<int>> arr(n,vector<int>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			arr[i][j] = i*n+j+1;
	cout<<"Before Rotating\n";
	cout<<arr;
	rotate(arr);
	cout<<"After Rotating\n";
	cout<<arr;
}