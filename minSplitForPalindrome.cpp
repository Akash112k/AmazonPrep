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

void longestPalindromeDP(string s,vector<vector<bool>> &isPalindrome)
{

	int n = s.length();
	for(int i=0;i<n;i++)
		isPalindrome[i][i]=true;
	for(int i=0;i<n-1;i++)
		if(s[i] == s[i+1])
			isPalindrome[i][i+1] = true;
	for(int len = 3;len<=n;len++)
	{
		for(int i=0;i<n-len+1;i++)
		{
			int j = i + len -1;
			isPalindrome[i][j] = isPalindrome[i+1][j-1] & (s[i] == s[j]);
		}
	}
	
}

void getMinSplit(string s)
{
	int n = s.length();
	vector<vector<bool>> isPalindrome(n,vector<bool>(n,false));
	vector<vector<int>> minSplit(n,vector<int>(n,INT_MAX));

	longestPalindromeDP(s,isPalindrome);

	for(int i=0;i<n;i++)
		minSplit[i][i] = 0;
	
	for(int i=0;i<n-1;i++)
		if(s[i] == s[i+1])
			minSplit[i][i+1] = 0;
		else
			minSplit[i][i+1] = 1;
	for(int len = 3;len<=n;len++)
	{
		for(int i = 0;i<n-len+1;i++)
		{
			int j = i + len -1;
			for(int k = i;k<j;k++)
			{
				int leftSubstring = isPalindrome[i][k] ? 0 : minSplit[i][k];
				int rightSubstring = isPalindrome[k+1][j] ? 0 : minSplit[k+1][j];
				minSplit[i][j] = min(minSplit[i][j],leftSubstring + rightSubstring + 1);
			}
		}
	}
	cout<<minSplit;
}

main()
{
	string s;
	cout<<"Enter the string\n";
	cin>>s;
	getMinSplit(s);
}