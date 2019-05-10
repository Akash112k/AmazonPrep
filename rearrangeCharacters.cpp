// Rearrange characters in a string such that no two adjacent are same

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
	bool isPossible = true;
	string s;
	cin>>s;
	string res = "";
	sort(s.begin(),s.end());
	int i=0,j=s.length()-1;
	while( i<=j && (s[i]!=s[j]) || (i==j && res.back()!=s[i]) ){
		res += s[i];
		if(i!=j)
			res += s[j];
		i++,j--;
	}
	if(i<=j)
		cout<<"Not Possible\n";
	else
		cout<<res<<endl;
}