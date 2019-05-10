/*

Word Break Problem | DP-32
Given an input string and a dictionary of words, 
find out if the input string can be segmented into
a space-separated sequence of dictionary words. 

See following examples for more details.

Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes 
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" 
or "i like sam sung".


*/


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
	set<string> st({"i","like","sam","sung","samsung","mobile","ice","cream","icecream","man","go","mango"});
	string s;
	cin>>s;
	vector<int> dp(s.length(),INT_MAX);
	for(int i=0;i<s.length();i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0){
				
				string temp = s.substr(j,i-j+1);
				if(st.find(temp)!=st.end())
					dp[i] = 0;
			}
			else{
				string temp = s.substr(j,i-j+1);
				if(dp[j-1]!=INT_MAX && st.find(temp)!=st.end())
					dp[i] = min(dp[i],dp[j-1]+1);
			}
		}
	}
	cout<<(dp.back()!=INT_MAX?dp.back():-1)<<endl;
}