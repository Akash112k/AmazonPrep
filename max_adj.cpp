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



// Max subsequence sum but no two elements can be adjacent
 
main()
{
	vector<int> arr;
	int n,i,one=0,two=0,ans=INT_MIN;
	cin>>n;
	for(i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	
	vector<int> dp(n,0);
	dp[0] = max(0,arr[0]);
	dp[1] = max(0,arr[1]);
	for(int i=2;i<n;i++)
		for(int j=0;j<i-1;j++)
			dp[i] = max(dp[i],dp[j]+arr[i]);
	
	cout<<dp<<endl;

}