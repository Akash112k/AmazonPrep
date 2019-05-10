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

int m_lower_bound(vector<int> &arr,int l,int r,int x)
{
	if(l==r)
		return arr[l]==x?l:arr.size();
	int mid = (l+r)/2;
	
	if(mid>0 && arr[mid]==x && arr[mid-1]!=x)
		return mid;
	if(mid==0 && arr[mid]==x)
		return mid;
	
	if(arr[mid]>=x)
		return m_lower_bound(arr,l,mid-1,x);
	return m_lower_bound(arr,mid+1,r,x);

}

int m_upper_bound(vector<int> &arr,int l,int r,int x)
{
	if(l==r)
		return arr[l]==x?l:arr.size();
	int mid = (l+r)/2;
	if(mid<(arr.size()-1) && arr[mid]==x && arr[mid+1]!=x)
		return mid;
	if(mid==arr.size()-1 && arr[mid]==x)
		return mid;
	
	if(arr[mid]>x)
		return m_upper_bound(arr,l,mid-1,x);
	return m_upper_bound(arr,mid+1,r,x);
}

main()
{
	int si,ei;
	vector<int> arr({1, 1, 1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 100, 100, 100, 100});
	si = m_lower_bound(arr,0,arr.size()-1,100);
	if( si != arr.size())
		ei = m_upper_bound(arr,0,arr.size()-1,100);
	cout<<si<<" "<<ei<<endl;
}