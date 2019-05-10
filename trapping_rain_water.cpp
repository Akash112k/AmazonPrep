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

main()
{
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(arr)/ sizeof(int);
	stack<int> stk;
	int totalVolume = 0;
	for(int i=0;i<n;i++)
	{
		int mx = 0,dist=0;
		
		while(stk.size()>0 && stk.top()<arr[i])
		{
			dist++;
			mx = max(mx,stk.top());
			stk.pop();
		}
		if(stk.size()>0){
			totalVolume += (min(arr[i],stk.top())-mx) * dist;
		}
		stk.push(arr[i]);
		cout<<"Total volume is "<<totalVolume<<endl;
	}
}