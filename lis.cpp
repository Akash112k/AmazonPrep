#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
#define pi pair<int,int>
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TESTS int TCASES;cin>>TCASES;while(TCASES--)
#define debug_log(a) cout<<"Debug Log -- "<<#a<<" is "<<a<<"\n";
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
	int n;
	cin>>n;
	vector<int> arr(n),lis(n,1);
	debug_log(n);

	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(arr[i]>arr[j])
				lis[i] = max(lis[i],lis[j]+1);
	int val = *max_element(lis.begin(),lis.end());
	
	for(int i=n-1;i>=0;i--){
		if(lis[i]==val){
			cout<<arr[i]<<" ";
			val--;
		}
	}

}